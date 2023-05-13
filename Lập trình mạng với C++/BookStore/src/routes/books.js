import express from 'express';
// const express = require("express");

import { book_ep } from '../app/controllers/BookController.js';

const routerBook = express.Router();
routerBook.get('/getAllBook', book_ep.getAllBook);
routerBook.get('/addBook', book_ep.form);
routerBook.post('/search', book_ep.searchByOption);
routerBook.post('/addBookAction', book_ep.addBook);
routerBook.get('/:slug', book_ep.show);
// routerHome.get('/', book.index);
export default routerBook;
