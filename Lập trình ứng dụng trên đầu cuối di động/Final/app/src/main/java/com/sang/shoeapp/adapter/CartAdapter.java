package com.sang.shoeapp.adapter;

import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.sang.shoeapp.R;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.model.Cart;
import com.sang.shoeapp.model.Product;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;
import com.sang.shoeapp.value_objects.CartId;
import com.squareup.picasso.Picasso;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class CartAdapter extends RecyclerView.Adapter<CartAdapter.CartViewHolder> {
    private final List<Product> mListCartItem;
    AlertDialog.Builder builderDialog;
    AlertDialog alertDialog;
    public CartAdapter(List<Product> mListCartItem) {
        this.mListCartItem = mListCartItem;
    }

    @NonNull
    @Override
    public CartViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_cart, parent, false);
        return new CartViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull CartViewHolder holder, int position) {
//        Cart cart = mListCartItem.get(position);
        Product product = mListCartItem.get(position);
        if (product == null) {
            return;
        }
        holder.textViewProductName.setText(product.getName());
        holder.textViewProductPrice.setText(String.valueOf(product.getPrice()) + " đ");
        Picasso.get().load(product.getImages().get(0).getUrl()).into(holder.imageViewItemCart);


        User user = DataLocalManager.getUser();
        CartId cartId = new CartId();
        cartId.cartId =user.getCartId();

        holder.imageViewDelete.setOnClickListener(new View.OnClickListener() {
            Api api = Api.getInstance();
            ShoeService shoeService = api.getShoeService();
            @Override
            public void onClick(View v) {
                AlertDialog.Builder alertDialog = new AlertDialog.Builder(holder.imageViewDelete.getContext());
                alertDialog.setTitle("Warning");
                alertDialog.setIcon(R.drawable.ic_baseline_warning_24);
                alertDialog.setMessage("Are you sure?");
                alertDialog.setPositiveButton("Yes", new DialogInterface.OnClickListener() {

                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        mListCartItem.remove(holder.getAdapterPosition());
                        notifyItemRemoved(holder.getAdapterPosition());

                        shoeService.removeProductFromCart(cartId, product.getId()).enqueue(new Callback<Cart>() {
                            @Override
                            public void onResponse(Call<Cart> call, Response<Cart> response) {
                                Log.d(TAG, "Delete successfully!");
                            }

                            @Override
                            public void onFailure(Call<Cart> call, Throwable t) {
                                Log.d(TAG, "Not get result");
                            }
                        });
//
                    }
                }).setNegativeButton("No", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                alertDialog.show();
            }
        });
    }


    @Override
    public int getItemCount() {
        if (mListCartItem != null) {
            return mListCartItem.size();
        }
        return 0;
    }

    public static class CartViewHolder extends RecyclerView.ViewHolder {
        private final TextView textViewProductName, textViewProductPrice;
        private final ImageView imageViewItemCart, imageViewDelete;

        public CartViewHolder(@NonNull View itemView) {
            super(itemView);
            textViewProductName = itemView.findViewById(R.id.product_name);
            textViewProductPrice = itemView.findViewById(R.id.product_price);
            imageViewDelete = itemView.findViewById(R.id.imageViewDelete);
            imageViewItemCart = itemView.findViewById(R.id.imageViewItemCart);
        }
    }

    private static final String TAG = "CartAdapter";
}
