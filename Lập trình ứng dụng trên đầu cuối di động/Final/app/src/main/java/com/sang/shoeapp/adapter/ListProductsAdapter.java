package com.sang.shoeapp.adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Filter;
import android.widget.Filterable;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.sang.shoeapp.R;
import com.sang.shoeapp.interfaces.IClickItemProductListener;
import com.sang.shoeapp.model.Product;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

public class ListProductsAdapter
        extends RecyclerView.Adapter<ListProductsAdapter.ListProductViewHolder>
        implements Filterable {
    private List<Product> mListItemProducts;
    private List<Product> mListItemProductsOld;
    private IClickItemProductListener iClickItemProductListener;

    public ListProductsAdapter(List<Product> mListItemProducts, IClickItemProductListener listener) {
        this.mListItemProducts = mListItemProducts;
        this.mListItemProductsOld = mListItemProducts;
        this.iClickItemProductListener = listener;
    }

    @NonNull
    @Override
    public ListProductViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_all_products, parent, false);
        return new ListProductViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ListProductViewHolder holder, int position) {
        final Product product = mListItemProducts.get(position);
        if (product == null) {
            return;
        }
        Picasso.get().load(product.getImages().get(0).getUrl()).into(holder.imageItemProducts);
        holder.textViewItemProductName.setText(product.getName());
        holder.textViewItemProductPrice.setText(String.valueOf(product.getPrice()));

        holder.relativeLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                iClickItemProductListener.onClickItemProduct(product);
            }
        });
    }

    @Override
    public int getItemCount() {
        if (mListItemProducts != null) {
            return mListItemProducts.size();
        }
        return 0;
    }

    @Override
    public Filter getFilter() {

        return new Filter() {
            @Override
            protected FilterResults performFiltering(CharSequence constraint) {
                String strSearch = constraint.toString();
                if (strSearch.isEmpty()) {
                    mListItemProducts = mListItemProductsOld;
                } else {
                    List<Product> list = new ArrayList<>();
                    for (Product product : mListItemProductsOld) {
                        if (product.getName().toLowerCase().contains(strSearch.toLowerCase())) {
                            list.add(product);
                        }
                    }
                    mListItemProducts = list;
                }
                FilterResults filterResults = new FilterResults();
                filterResults.values = mListItemProducts;
                return filterResults;
            }

            @Override
            protected void publishResults(CharSequence constraint, FilterResults results) {
                mListItemProducts = (List<Product>)results.values;
                notifyDataSetChanged();
            }
        };
    }

    public static class ListProductViewHolder extends RecyclerView.ViewHolder {
        private final ImageView imageItemProducts;
        private final TextView textViewItemProductName, textViewItemProductPrice;
        private RelativeLayout relativeLayout;


        public ListProductViewHolder(@NonNull View itemView) {
            super(itemView);
            imageItemProducts = itemView.findViewById(R.id.imageItemProducts);
            textViewItemProductName = itemView.findViewById(R.id.textViewItemProductName);
            textViewItemProductPrice = itemView.findViewById(R.id.textViewItemProductPrice);
            relativeLayout = itemView.findViewById(R.id.layout_item);
        }
    }
}
