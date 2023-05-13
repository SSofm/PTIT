package com.sang.shoeapp.activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.SearchView;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.animation.AnimationUtils;
import android.view.animation.LayoutAnimationController;

import com.sang.shoeapp.R;
import com.sang.shoeapp.adapter.ListProductsAdapter;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.interfaces.IClickItemProductListener;
import com.sang.shoeapp.model.Product;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class Vans extends AppCompatActivity {
    private RecyclerView recyclerViewItemProducts;
    private ListProductsAdapter listProductsAdapter;
    private List<Product> mListProduct;
    private static final String TAG = "VansActivity";

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vans);
        recyclerViewItemProducts = findViewById(R.id.rcv_item_products);
        mListProduct = new ArrayList<>();
        LayoutAnimationController layoutAnimationController = AnimationUtils
                .loadLayoutAnimation(this, R.anim.layout_animation_left_to_right);
        recyclerViewItemProducts.setLayoutAnimation(layoutAnimationController);
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this);
        recyclerViewItemProducts.setLayoutManager(linearLayoutManager);
        DividerItemDecoration itemDecoration = new DividerItemDecoration(this, DividerItemDecoration.VERTICAL);
        recyclerViewItemProducts.addItemDecoration(itemDecoration);
        callApiProduct();
    }
    public void callApiProduct() {
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();
        shoeService.getAllProductsByBrand("Vans").enqueue(new Callback<List<Product>>() {
            @Override
            public void onResponse(Call<List<Product>> call, Response<List<Product>> response) {
                mListProduct = response.body();
                listProductsAdapter = new ListProductsAdapter(mListProduct, new IClickItemProductListener() {
                    @Override
                    public void onClickItemProduct(Product product) {
                        onClickGoToDetail(product);
                    }
                });
                recyclerViewItemProducts.setAdapter(listProductsAdapter);
            }

            @Override
            public void onFailure(Call<List<Product>> call, Throwable t) {
                Log.d(TAG, "onFailure: " + t.getMessage());
            }
        });
    }
    private void onClickGoToDetail(Product product) {
        Intent intent = new Intent(this, DetailActivity.class);
        Bundle bundle = new Bundle();
        bundle.putSerializable("object_product", product);
        intent.putExtras(bundle);
        this.startActivity(intent);
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
    }
}