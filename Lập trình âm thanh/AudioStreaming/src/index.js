// const express = require("express");
// const morgan = require("morgan");
import express from "express";
import morgan from "morgan";
import dotenv from "dotenv";
import { create } from "express-handlebars";
import path from "path";
import { fileURLToPath } from "url";
import mongoose from 'mongoose';
import mongodb from 'mongodb';
import fs from 'fs';
// import res from "express/lib/response";

dotenv.config();

const app = express();

// use morgan
app.use(morgan('combined'));

// static file
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
app.use(express.static(path.join(__dirname, 'public')));


// connect to mongo db
// mongoose.connect(process.env.MONGODB_URL, () => {
//   console.log("Connected to mongodb");
// })

// const hbs = create({ /* config */});
const hbs = create({extname: '.hbs'});


// handlebars template
app.engine(".hbs", hbs.engine);
app.set("view engine", ".hbs");


app.set("views", path.join(__dirname, "resources/views"));

// app.get('/', (req, res) => {
//     res.sendFile(__dirname + '/index.html');
// });
app.get('/', (req, res) => {
    res.render('home');
});
app.get('/home/Spelling', (req, res) => {
    res.render('Spelling');
});
app.get('/home/Toeic', (req, res) => {
    res.render('Toeic');
});

app.get('/stream', (req, res, stt) => {
    const file = __dirname + '/public/Audio/stt.mp3';
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
