import mongoose from 'mongoose';
async function connect() {
  try {
    await mongoose.connect('mongodb://localhost:27017/Book_Store', {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    });
    console.log('Connect Successfully!');
  } catch (error) {
    console.log('Connect Fail!');
  }
}
module.exports = { connect };
