package com.sang.shoeapp;

import android.app.Application;

import com.sang.shoeapp.shared.DataLocalManager;

public class MyApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        DataLocalManager.init(getApplicationContext());
    }
}
