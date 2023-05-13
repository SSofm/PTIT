package com.sang.shoeapp.fragments;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.viewpager2.widget.ViewPager2;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.activities.DetailActivity;
import com.sang.shoeapp.activities.Vans;
import com.sang.shoeapp.adapter.PhotoViewPager2;
import com.sang.shoeapp.adapter.ProductAdapter;
import com.sang.shoeapp.adapter.ZoomOutPageTransformer;
import com.sang.shoeapp.all_product_activity;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.interfaces.IClickItemProductListener;
import com.sang.shoeapp.model.Photo;
import com.sang.shoeapp.model.Product;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;

import java.util.ArrayList;
import java.util.List;

import de.hdodenhof.circleimageview.CircleImageView;
import me.relex.circleindicator.CircleIndicator3;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class HomeFragment extends Fragment {
    CircleImageView profile;
    TextView emailUser;
    ImageView imageViewSearchBtn, imageViewVansBrand;
    private RecyclerView recyclerViewProducts;
    private ImageView imageViewCart;
    private List<Product> mListProduct;
    private ViewPager2 mViewPager2;
    private CircleIndicator3 mCircleIndicator3;
    private List<Photo> mListPhoto;

    private final Handler mHandler = new Handler();
    private final Runnable mRunable = new Runnable() {
        @Override
        public void run() {
            if (mViewPager2.getCurrentItem() == mListPhoto.size() - 1) {
                mViewPager2.setCurrentItem(0);
            } else {
                mViewPager2.setCurrentItem(mViewPager2.getCurrentItem() + 1);
            }

        }
    };

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState
    ) {
        View view = inflater.inflate(R.layout.home_fragment, container, false);
        profile = (CircleImageView) view.findViewById(R.id.linkProfile);
        imageViewSearchBtn = view.findViewById(R.id.searchBtn);
        imageViewCart = (ImageView) view.findViewById(R.id.cart);
        imageViewVansBrand = (ImageView) view.findViewById(R.id.vans_brand);
        emailUser = (TextView) view.findViewById(R.id.emailUser);
        mListProduct = new ArrayList<>();
        mViewPager2 = view.findViewById(R.id.view_pager_2);
        mCircleIndicator3 = view.findViewById(R.id.circle_indicator_3);
        mListPhoto = getListPhoto();
        PhotoViewPager2 adapter = new PhotoViewPager2(mListPhoto);
        mViewPager2.setAdapter(adapter);

        mCircleIndicator3.setViewPager(mViewPager2);


        mViewPager2.registerOnPageChangeCallback(new ViewPager2.OnPageChangeCallback() {
            @Override
            public void onPageSelected(int position) {
                super.onPageSelected(position);
                mHandler.removeCallbacks(mRunable);
                mHandler.postDelayed(mRunable, 5000);
            }
        });

        mViewPager2.setPageTransformer(new ZoomOutPageTransformer());
        User user = DataLocalManager.getUser();
        if (user != null) {
            emailUser.setText(user.getUsername());
//            emailUser.setText(String.valueOf(user.getCartId()));
        }
        recyclerViewProducts = (RecyclerView) view.findViewById(R.id.rcv_products);
//        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getContext());
        GridLayoutManager gridLayoutManager = new GridLayoutManager(getContext(), 2);
        recyclerViewProducts.setLayoutManager(gridLayoutManager);
        DividerItemDecoration itemDecoration = new DividerItemDecoration(getContext(), DividerItemDecoration.VERTICAL);
        recyclerViewProducts.addItemDecoration(itemDecoration);
        callApiProduct();


        return view;
    }

    private List<Photo> getListPhoto() {
        List<Photo> list = new ArrayList<>();
        list.add(new Photo(R.drawable.slide1));
        list.add(new Photo(R.drawable.slide2));
        list.add(new Photo(R.drawable.slide3));
        list.add(new Photo(R.drawable.slide4));
        list.add(new Photo(R.drawable.slide5));

        return list;
    }

    public void callApiProduct() {
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();
        shoeService.getListProducts().enqueue(new Callback<List<Product>>()
//        shoeService.getListProductsWithCoverImage().enqueue(new Callback<List<Product>>()
        {
            @Override
            public void onResponse(Call<List<Product>> call, Response<List<Product>> response) {
                mListProduct = response.body();
                ProductAdapter productAdapter = new ProductAdapter(mListProduct, new IClickItemProductListener() {
                    @Override
                    public void onClickItemProduct(Product product) {
                        onClickGoToDetail(product);
                    }
                });
                recyclerViewProducts.setAdapter(productAdapter);
            }

            @Override
            public void onFailure(Call<List<Product>> call, Throwable t) {
                Log.d(TAG, "onFailure: " + t.getMessage());
            }
        });
    }

    @Override
    public void onPause() {
        super.onPause();
        mHandler.removeCallbacks(mRunable);
    }

    @Override
    public void onResume() {
        super.onResume();
        mHandler.postDelayed(mRunable, 5000);
    }

    private void onClickGoToDetail(Product product) {
        Intent intent = new Intent(getContext(), DetailActivity.class);
        Bundle bundle = new Bundle();
        bundle.putSerializable("object_product", product);
        intent.putExtras(bundle);
        getContext().startActivity(intent);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        profile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goProfile();
            }
        });

        imageViewSearchBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent fp=new Intent(getActivity(), all_product_activity.class);
                startActivity(fp);
            }
        });

        imageViewCart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goCart();
            }
        });
        imageViewVansBrand.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent fp=new Intent(getActivity(), Vans.class);
                startActivity(fp);
            }
        });
    }

    private static final String TAG = "HomeFragment";
}
