const express = require("express");
const app = express();
const fs = require("fs");
const path = require('path');
require('dotenv').config;

app.use(express.static(path.join(__dirname)));

app.get("/",  (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.get("/video", function (req, res) {
  // Ensure there is a range given for the video
  const range = req.headers.range;
  if (!range) {
    res.status(400).send("Requires Range header");
  }

  // get video stats (about 61MB)
  const videoPath = "./Data/Videos/XXXTENTACION - Everybody Dies In Their Nightmares (Audio).mp4";
  const videoSize = fs.statSync("./Data/Videos/XXXTENTACION - Everybody Dies In Their Nightmares (Audio).mp4").size;

  // Parse Range
  // Example: "bytes=32324-"
  const CHUNK_SIZE = 10 ** 6; // 1MB
  const start = Number(range.replace(/\D/g, ""));
  const end = Math.min(start + CHUNK_SIZE, videoSize - 1);

  // Create headers
  const contentLength = end - start + 1;
  const headers = {
    "Content-Range": `bytes ${start}-${end}/${videoSize}`,
    "Accept-Ranges": "bytes",
    "Content-Length": contentLength,
    "Content-Type": "video/mp4",
  };

  // HTTP Status 206 for Partial Content
  res.writeHead(206, headers);

  // create video read stream for this particular chunk
  const videoStream = fs.createReadStream(videoPath, { start, end });

  // Stream the video chunk to the client
  videoStream.pipe(res);
});

app.get('/audioStreaming', (req, res) => {
  const file = __dirname + '/Data/Audio/1.mp3';
  const stat = fs.statSync(file);
  const total = stat.size;
  if (req.headers.range) {

  }
  fs.exists(file, (exists) => {
      if (exists) {
          const range = req.headers.range;
          const parts = range.replace(/bytes=/, '').split('-');
          const partialStart = parts[0];
          const partialEnd = parts[1];

          const start = parseInt(partialStart, 10);
          const end = partialEnd ? parseInt(partialEnd, 10) : total - 1;
          const chunksize = (end - start) + 1;
          const rstream = fs.createReadStream(file, {start: start, end: end});
    
    
          res.writeHead(206, {
              'Content-Range': 'bytes ' + start + '-' + end + '/' + total,
              'Accept-Ranges': 'bytes', 'Content-Length': chunksize,
              'Content-Type': 'audio/mpeg'
          });
          rstream.pipe(res);

      } else {
          res.send('Error - 404');
          res.end();
          // res.writeHead(200, { 'Content-Length': total, 'Content-Type': 'audio/mpeg' });
          // fs.createReadStream(path).pipe(res);
      }
  });
});

app.listen(process.env.PORT || 5000);
