package com.sang.shoeapp.adapter;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.sang.shoeapp.R;
import com.sang.shoeapp.activities.DetailActivity;
import com.sang.shoeapp.fragments.DetailProductFragment;
import com.sang.shoeapp.interfaces.IClickItemProductListener;
import com.sang.shoeapp.model.Product;
import com.squareup.picasso.Picasso;

import java.util.List;

public class ProductAdapter extends RecyclerView.Adapter<ProductAdapter.ProductViewHolder> {
    private List<Product> mListProduct;
    private IClickItemProductListener iClickItemProductListener;

    public ProductAdapter(List<Product> mListProduct, IClickItemProductListener listener) {
        this.mListProduct = mListProduct;
        this.iClickItemProductListener = listener;
    }

    @NonNull
    @Override
    public ProductViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_product, parent, false);
        return new ProductViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ProductViewHolder holder, int position) {
        final Product product = mListProduct.get(position);
        if (product == null) {
            return;
        }
        holder.tvTitle.setText(product.getName());
        holder.tvPrice.setText(String.valueOf(product.getPrice()) + " đ");
        Picasso.get().load(product.getImages().get(0).getUrl()).into(holder.imageView);

        holder.layoutProduct.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                iClickItemProductListener.onClickItemProduct(product);
            }
        });
    }

    @Override
    public int getItemCount() {
        if (mListProduct != null) {
            return mListProduct.size();
        }
        return 0;
    }

    public static class ProductViewHolder extends RecyclerView.ViewHolder {
        private final TextView tvTitle, tvPrice;
        private final ImageView imageView;
        private LinearLayout layoutProduct;

        public ProductViewHolder(@NonNull View itemView) {
            super(itemView);
            tvTitle = itemView.findViewById(R.id.tv_title);
            tvPrice = itemView.findViewById(R.id.tv_price);
            imageView = itemView.findViewById(R.id.imageview);
            layoutProduct = itemView.findViewById(R.id.layout_product);
        }
    }
}
