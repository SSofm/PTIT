import express from 'express';
// const express = require("express");

import { site } from '../app/controllers/SiteController.js';

const routerHome = express.Router();
routerHome.get('/search', site.search);
// export default router.use("/", homeController);
routerHome.get('/', site.index);
// module.exports = routerHome;
export default routerHome;
