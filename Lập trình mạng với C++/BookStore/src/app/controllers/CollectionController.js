import { collection } from "../models/Collection";
import { book } from "../models/Book";
import { multipleMongooseToObject } from "../../util/mongoose";
import { mongooseToObject } from "../../util/mongoose";
import { bookCollectionModels } from "../../data/bookCollections";

class CollectionController {
  show(req, res, next) {
    collection
      .findOne({ userId: "PT190" })
      .then((collection) => {
        const bookData = [];
        collection.listBookId.forEach((element) => {
          bookCollectionModels.forEach((book) => {
            if (book.id === element) {
              bookData.push(book);
            }
          });
        });
        res.render("Collection/collectionUI", {
          //   collection: mongooseToObject(collection),
          bookData: bookData,
        });
      })
      .catch(next);
  }
  show2(req, res, next) {
    collection
      .findOne({ userId: "PT190" })
      .then((collection) => {
        res.render(
          "Collection/collectionUI",
          JSON.stringify({
            collection: mongooseToObject(collection),
            book: multipleMongooseToObject(book),
          })
        );
        res.send("hello");
        // res.json(collection);
        // collection.listBookId.forEach( i => console.log(i));

        // console.log(collection.listBookId);
        // book
        //     .find({id:{ $in: collection.listBookId }})
        //     .then((book) => {
        //         res.render('Collection/collectionUI', { book: multipleMongooseToObject(book) });
        //     })
        //     .catch(next);
      })
      .catch(next);
  }
  //   add/collection/:bookId
  
  addCollection(req, res, next) {
    const { bookId } = req.params;
    collection
      .findOneAndUpdate(
        { userId: "PT190" },
        {
          $addToSet: { listBookId: bookId },
        },
        {
          new: true,
        }
      )
      .then(()=>
        res.redirect('back')
        // console.log("add succ")
      )
      .catch(next);
  }

  delCollection(req, res, next) {
    const { bookId } = req.params;
    console.log(bookId);
    collection
      .update(
        { userId: "PT190" },
        {
            $pull: { listBookId: bookId },
        },
      )
      .then(() => 
       res.redirect('back')

        // console.log("del succ");
        )
      .catch(next);
  }
}

const collection_ep = new CollectionController();
export { collection_ep };
