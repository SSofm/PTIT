package com.sang.shoeapp.fragments;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.value_objects.UserRequest;
import com.sang.shoeapp.value_objects.UserRespone;


import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class SignUpFragment extends Fragment {
    EditText usernameEt, emailEt, passwordEt;
    Button submitBtn;
    TextView linkSignIn;

    @Nullable
    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater,
            @Nullable ViewGroup container,
            @Nullable Bundle savedInstanceState
    ) {
        View view = inflater.inflate(R.layout.signup_fragment, container, false);
        usernameEt = (EditText) view.findViewById(R.id.usernameInput);
        emailEt = (EditText) view.findViewById(R.id.emailInput);
        passwordEt = (EditText) view.findViewById(R.id.passwordInput);
        submitBtn = (Button) view.findViewById(R.id.submitBtn);
        linkSignIn = (TextView) view.findViewById(R.id.linkSignIn);
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();

        linkSignIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goSignIn();
            }
        });

        submitBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                UserRequest userRequest = new UserRequest();
                userRequest.username = usernameEt.getText().toString();
                userRequest.email = emailEt.getText().toString();
                userRequest.password = passwordEt.getText().toString();
                Log.d(TAG, "username is: " + usernameEt.getText().toString());
                shoeService.signUp(userRequest).enqueue(new Callback<UserRespone>() {
                    @Override
                    public void onResponse(Call<UserRespone> call, Response<UserRespone> response) {
                        if (String.valueOf(response.code()).charAt(0) == '2') {
                            ((MainActivity) getActivity()).goSignIn();
                            Log.d(TAG, "email response: " + response.body().username);
                        } else {
                            Log.d(TAG, "Not get result");
                        }
                    }

                    @Override
                    public void onFailure(Call<UserRespone> call, Throwable t) {
                        Log.d(TAG, "onFailure: " + t.getMessage());
                    }
                });
            }
        });

    }

    private static final String TAG = "SignUpFragment";
}
