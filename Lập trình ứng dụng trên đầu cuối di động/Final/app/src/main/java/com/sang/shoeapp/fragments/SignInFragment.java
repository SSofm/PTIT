package com.sang.shoeapp.fragments;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;
import com.sang.shoeapp.value_objects.UserRequest;
import com.sang.shoeapp.value_objects.UserRespone;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class SignInFragment extends Fragment {
    EditText emailEt, passwordEt;
    Button submitBtn;
    TextView linkSignUp;
    CheckBox checkbox;

    @Nullable
    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater,
            @Nullable ViewGroup container,
            @Nullable Bundle savedInstanceState
    ) {
        View view = inflater.inflate(R.layout.signin_fragment, container, false);
        emailEt = (EditText) view.findViewById(R.id.emailInput);
        passwordEt = (EditText) view.findViewById(R.id.passwordInput);
        submitBtn = (Button) view.findViewById(R.id.submitBtn);
        linkSignUp = (TextView) view.findViewById(R.id.linkSignUp);
        checkbox = (CheckBox) view.findViewById(R.id.checkBoxRememberMe);
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();

        submitBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                UserRequest userRequest = new UserRequest();
                userRequest.email = emailEt.getText().toString();
                userRequest.password = passwordEt.getText().toString();
                shoeService.signIn(userRequest).enqueue(new Callback<UserRespone>() {
                    @Override
                    public void onResponse(Call<UserRespone> call, Response<UserRespone> response) {
                        if (String.valueOf(response.code()).charAt(0) == '2') {
                            if(checkbox.isChecked()){
                                DataLocalManager.setRememberMe(true);
                            }else{
                                DataLocalManager.setRememberMe(false);
                            }
                            ((MainActivity) getActivity()).goHome();
//                            Log.d(TAG, "onResponse sign in: " + response.body());
                            User user = new User(response.body().id, response.body().username, response.body().email, response.body().cartId);
                            DataLocalManager.setUser(user);
                        } else {
                            Toast toast = Toast.makeText(getContext(), "Your email/password do not match. Please try again!", Toast.LENGTH_LONG);
                            toast.setGravity(Gravity.TOP | Gravity.CENTER, 20, 30);
                            toast.show();
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

        linkSignUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goSignUp();
            }
        });
    }

    private static final String TAG = "SignInFragment";
}
