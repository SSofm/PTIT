// import Book from '../models/Book';
import { book } from '../models/Book';
import { multipleMongooseToObject } from '../../util/mongoose';
// const Book = require('../models/Book');
class SiteController {
  // trang home
  index(req, res, next) {
    book
      .find({})
      .then((books) => {
        res.render('home', {
          books: multipleMongooseToObject(books),
        });
      })
      .catch(next);
  }

  // trang con trong trang home
  /*
    GET /search
  */
  search(req, res) {
    res.send('search');
  }
}

// module.exports = new HomeController;

// export default HomeController;
const site = new SiteController();
export { site };
//export {new HomeController() }
