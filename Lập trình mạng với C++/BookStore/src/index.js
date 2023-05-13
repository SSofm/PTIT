// const express = require("express");
// const morgan = require("morgan");
import express from "express";
import morgan from "morgan";
import dotenv from "dotenv";
import { create } from "express-handlebars";
import path from "path";
import { fileURLToPath } from "url";
import mongoose from "mongoose";
import mongodb from "mongodb";
import fs from "fs";
import cookieParser from "cookie-parser";
import session from "express-session";
import bodyParser from "body-parser";

import route from "./routes/index.js";
// const route = require("./routes");

dotenv.config();

const app = express();
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
app.use(express.static(path.join(__dirname, "public")));

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(cookieParser("secret"));
app.use(session({ cookie: { maxAge: null } }));
app.use(express.json()); // for parsing application/json
app.use(express.urlencoded({ extended: true })); // for parsing application/x-www-form-urlencoded

//flash message middleware
app.use((req, res, next) => {
  res.locals.message = req.session.message;
  delete req.session.message;
  next();
});

// connect to mongo db
mongoose.connect(process.env.MONGODB_URL, () => {
  console.log("Connected to mongodb");
});

// const hb s = create({ /* config */});
const hbs = create({ extname: ".hbs" });

const port = 3000;

// template
app.engine(".hbs", hbs.engine);
app.set("view engine", ".hbs");

app.set("views", path.join(__dirname, "resources", "views"));

// console.log(__dirname);

// http logger
app.use(morgan("combined"));

// route init
route(app);

app.listen(process.env.PORT || 5000);
