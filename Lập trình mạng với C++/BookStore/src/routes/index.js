import newRouter from './home.js';
import siteRouter from './site.js';
import bookRouter from './books.js';
import collectionRouter from './collection.js';

// import routerHome from "./home";

// const newRouter = require('./home');
export default function route(app) {
  app.use('/home', newRouter);
  app.use('/books', bookRouter);
  app.use('/collection', collectionRouter);
  app.use('/', siteRouter);
}
// module.exports = route;
