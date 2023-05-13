import mongoose from 'mongoose';
const Schema = mongoose.Schema;

const User = new Schema({
  username: { type: String, default: 'Name Card', maxlength: 100 },
  password: { type: String, min: 18, maxlength: 600 },
  image: { type: String, maxlength: 500 },
  slug: { type: String, maxlength: 255 }
},
{
  timestamps: true, 
});
const user = mongoose.model('User', User);
export { user };
// export default mongoose.model('Book', Book);
