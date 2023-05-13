

class HomeController {
  index(req, res) {
    res.render('home');
  }

  // trang con trong trang home
  /*
    GET /home/:slug
  */
  show(req, res) {
    res.send('home detail!');
  }
}

// module.exports = new HomeController;

// export default HomeController;
const home = new HomeController();
export { home };
//export {new HomeController() }
