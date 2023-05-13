import express from 'express';
// const express = require("express");

import { collection_ep } from '../app/controllers/CollectionController.js';

const routerCollection = express.Router();
routerCollection.get('/', collection_ep.show);
routerCollection.post('/:bookId/delete', collection_ep.delCollection);
routerCollection.post('/:bookId', collection_ep.addCollection);
// routerHome.get('/', home.index);
// module.exports = routerHome;
export default routerCollection;
