package com.sang.shoeapp.fragments;

import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.widget.AppCompatButton;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.adapter.CartAdapter;

import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.model.Cart;
import com.sang.shoeapp.model.Invoice;
import com.sang.shoeapp.model.Product;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class CartFragment extends Fragment {

    private RecyclerView recyclerViewItemsCart;
    //    private List<Cart> mListItemsCart;
    private List<Product> mListItemsCart;
    int totalPrice = 0;
    private TextView textViewTotal;
    private ImageView backBtn;
    private Button paymentBtn;
    AlertDialog.Builder builderDialog;
    AlertDialog alertDialog;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.cart_fragment, container, false);
        backBtn = view.findViewById(R.id.backBtn);
        textViewTotal = view.findViewById(R.id.total);
        paymentBtn = view.findViewById(R.id.paymentBtn);
        recyclerViewItemsCart = view.findViewById(R.id.recycleViewCart);
        mListItemsCart = new ArrayList<>();
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getContext());
        recyclerViewItemsCart.setLayoutManager(linearLayoutManager);
        DividerItemDecoration itemDecoration = new DividerItemDecoration(getContext(), DividerItemDecoration.VERTICAL);
        recyclerViewItemsCart.addItemDecoration(itemDecoration);

        callApiGetItemsInCart();
        return view;
    }

    private void callApiGetItemsInCart() {
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();
        User user = DataLocalManager.getUser();

        shoeService.getListItemsInCart(user.getCartId()).enqueue(new Callback<List<Product>>() {
            @Override
            public void onResponse(Call<List<Product>> call, Response<List<Product>> response) {
                mListItemsCart = response.body();
                for (int i = 0; i < mListItemsCart.size(); i++) {
                    totalPrice += mListItemsCart.get(i).getPrice();
                }
                textViewTotal.setText("Tổng thanh toán: " + String.valueOf(totalPrice) + " đ");
                CartAdapter cartAdapter = new CartAdapter(mListItemsCart);
                recyclerViewItemsCart.setAdapter(cartAdapter);
            }

            @Override
            public void onFailure(Call<List<Product>> call, Throwable t) {
                Log.d(TAG, "onFailure: " + t.getMessage());
            }
        });
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();
        User user = DataLocalManager.getUser();


        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goHome();
            }
        });
        paymentBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                shoeService.createNewInvoice(user.getId()).enqueue(new Callback<Invoice>() {
                    @Override
                    public void onResponse(Call<Invoice> call, Response<Invoice> response) {
                        showAlertDialog(R.layout.payment_successful);

                    }

                    @Override
                    public void onFailure(Call<Invoice> call, Throwable t) {
                        Log.d(TAG, "Not get result");
                    }
                });
            }
        });
    }

    private void showAlertDialog(int myLayout) {
        builderDialog = new AlertDialog.Builder((Context) getActivity());
        View layoutView = getLayoutInflater().inflate(myLayout, null);
        AppCompatButton dialogButton = layoutView.findViewById(R.id.buttonOk);
        builderDialog.setView(layoutView);
        alertDialog = builderDialog.create();
        alertDialog.show();


        // click on OK button
        dialogButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                alertDialog.dismiss();
            }
        });
    }

    private static final String TAG = "CartFragment";
}
