package com.sang.shoeapp.api;

import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class Api {
    private static Api instance;
    private Retrofit retrofit;
    private ShoeService shoeService;

    public ShoeService getShoeService() {
        return shoeService;
    }

    public Api() {
        retrofit = new Retrofit.Builder()
                .baseUrl("http://192.168.0.103:3000")
                .addConverterFactory(GsonConverterFactory.create())
                .build();
        shoeService = retrofit.create(ShoeService.class);
    }

    public static Api getInstance() {
        if (instance == null) {
            instance = new Api();
        }
        return instance;
    }
}
