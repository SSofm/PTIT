package com.sang.shoeapp.fragments;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;

public class DetailProductFragment extends Fragment {
    private ImageView backBtn;
    private TextView productName, productPrice, productDescription;
    @SuppressLint("MissingInflatedId")
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.detail_product_fragment, container, false);
        backBtn = (ImageView) view.findViewById(R.id.backBtn);
        productName = (TextView) view.findViewById(R.id.productName);
        productPrice = (TextView) view.findViewById(R.id.productPrice);
        productDescription= (TextView) view.findViewById(R.id.productDescription);


        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goHome();
            }
        });
    }
}
