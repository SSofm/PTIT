import mongoose from 'mongoose';
const Schema = mongoose.Schema;

const Book = new Schema({
  name: { type: String, default: 'Name Card', maxlength: 100 },
  description: { type: String, min: 18, maxlength: 600 },
  image: { type: String, maxlength: 500 },
  slug: { type: String, maxlength: 255 },
  author: { type: String, maxlength: 100 },
  category: { type: String, maxlength: 100 },
},
{
  timestamps: true, 
});
const book = mongoose.model('Book', Book);
export { book };

