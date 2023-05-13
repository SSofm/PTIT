import express from 'express';
// const express = require("express");

import { home } from '../app/controllers/HomeController.js';

const routerHome = express.Router();
routerHome.get('/:slug', home.show);
// export default router.use("/", homeController);
routerHome.get('/', home.index);
// module.exports = routerHome;
export default routerHome;
