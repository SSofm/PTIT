import mongoose from "mongoose";
const Schema = mongoose.Schema;

const Collection = new Schema(
  {
    id: { type: String, required: true },
    userId: {
      type: String,
      required: true,
      ref: "User",
    },
    listBookId: {
      type: Array
    },
  },
  {
    timestamps: true,
  }
);
const collection = mongoose.model("Collection", Collection);
export { collection };
