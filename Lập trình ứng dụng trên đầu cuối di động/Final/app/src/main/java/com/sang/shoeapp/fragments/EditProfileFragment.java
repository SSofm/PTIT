package com.sang.shoeapp.fragments;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.widget.AppCompatButton;
import androidx.fragment.app.Fragment;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.api.Api;
import com.sang.shoeapp.api.ShoeService;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;
import com.sang.shoeapp.value_objects.UpdateUserProfile;
import com.sang.shoeapp.value_objects.UserRequest;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class EditProfileFragment extends Fragment {
    TextView usernameInput, emailInput;
    Button resetBtn, updateBtn;
    ImageView backBtn;
    AlertDialog.Builder builderDialog;
    AlertDialog alertDialog;


    @SuppressLint("MissingInflatedId")
    @Nullable
    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater,
            @Nullable ViewGroup container,
            @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.edit_profile_fragment, container, false);
        usernameInput = (TextView) view.findViewById(R.id.usernameInput);
        emailInput = (TextView) view.findViewById(R.id.emailInput);
        resetBtn = (Button) view.findViewById(R.id.resetBtn);
        updateBtn = (Button) view.findViewById(R.id.updateBtn);
        backBtn = (ImageView) view.findViewById(R.id.backBtn);

        User user = DataLocalManager.getUser();
        if (user != null) {
            usernameInput.setText(user.getUsername());
            emailInput.setText(user.getEmail());
        }
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Api api = Api.getInstance();
        ShoeService shoeService = api.getShoeService();
        resetBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                User user = DataLocalManager.getUser();
                usernameInput.setText(user.getUsername());
                emailInput.setText(user.getEmail());
            }
        });
        updateBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                UserRequest userRequest = new UserRequest();
                userRequest.username = usernameInput.getText().toString();
                userRequest.email = emailInput.getText().toString();
                shoeService.updateProfile(DataLocalManager.getUser().getId(), userRequest).enqueue(new Callback<UpdateUserProfile>() {
                    @Override
                    public void onResponse(Call<UpdateUserProfile> call, Response<UpdateUserProfile> response) {
                        if (String.valueOf(response.code()).charAt(0) == '2') {
                            showAlertDialog(R.layout.success_alert_dialog);
                            ((MainActivity) getActivity()).goHome();
//                            Log.d(TAG, "onResponse sign in: " + response.body());
                            User user = new User(response.body().id, response.body().username, response.body().email, response.body().cartId);
                            DataLocalManager.setUser(user);
                        }
                    }
                    @Override
                    public void onFailure(Call<UpdateUserProfile> call, Throwable t) {
                        Log.d(TAG, "onFailure: " + t.getMessage());
                    }
                });

            }
        });
        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goProfile();
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
    private static final String TAG = "EditProfileFragment";
}
