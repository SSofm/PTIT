package com.sang.shoeapp;


import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import com.sang.shoeapp.fragments.CartFragment;
import com.sang.shoeapp.fragments.DetailProductFragment;
import com.sang.shoeapp.fragments.EditProfileFragment;
import com.sang.shoeapp.fragments.HomeFragment;
import com.sang.shoeapp.fragments.ProfileFragment;
import com.sang.shoeapp.fragments.SignInFragment;
import com.sang.shoeapp.fragments.SignUpFragment;
import com.sang.shoeapp.shared.DataLocalManager;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        SharedPreferences sharedPreferences = getSharedPreferences("MY_SHARED_PREFERENCES", Context.MODE_PRIVATE);

//        if (sharedPreferences.getBoolean("PRE_FIRST_LOGIN", false)) {
//            getSupportFragmentManager().beginTransaction()
//                    .replace(R.id.container, new HomeFragment()).commit();
//        } else {
//            getSupportFragmentManager().beginTransaction()
//                    .replace(R.id.container, new SignInFragment()).commit();
//        }
        Log.d(TAG, "test get remember me: " + DataLocalManager.getRememberMe());
        if (DataLocalManager.getRememberMe()) {
            Log.d(TAG, "test get remember me: " + DataLocalManager.getRememberMe());
            getSupportFragmentManager().beginTransaction()
                    .replace(R.id.container, new HomeFragment()).commit();
        } else {
            getSupportFragmentManager().beginTransaction()
                    .replace(R.id.container, new SignInFragment()).commit();
        }
        if (!DataLocalManager.getFirstInstalled()) {
            Toast.makeText(this, "First installed app!", Toast.LENGTH_LONG).show();
            DataLocalManager.setFirstInstalled(true);
        }


    }

    public void goHome() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new HomeFragment()).commit();
    }

    public void goSignUp() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new SignUpFragment()).commit();
    }

    public void goSignIn() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new SignInFragment()).commit();
    }

    public void goProfile() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new ProfileFragment()).commit();
    }

    public void goEditProfile() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new EditProfileFragment()).commit();
    }

    public void goDetailProduct() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new DetailProductFragment()).commit();
    }
    public void goCart() {
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container, new CartFragment()).commit();
    }

}