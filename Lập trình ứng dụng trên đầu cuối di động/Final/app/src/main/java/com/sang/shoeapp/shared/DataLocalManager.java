package com.sang.shoeapp.shared;

import android.content.Context;

import com.google.gson.Gson;
import com.sang.shoeapp.model.User;

import java.util.Set;

public class DataLocalManager {
    private static final String PRE_FIRST_INSTALL = "PRE_FIRST_INSTALL";
    private static final String PRE_FIRST_LOGIN = "PRE_FIRST_LOGIN";
    private static final String PRE_USER_NAME = "PRE_USER_NAME";
    private static final String PRE_OBJECT_USER = "PRE_OBJECT_USER";
    private static DataLocalManager instance;
    private MySharedPreferences mySharedPreferences;


    public static void init(Context context) {
        instance = new DataLocalManager();
        instance.mySharedPreferences = new MySharedPreferences(context);
    }

    public static DataLocalManager getInstance() {
        if (instance == null) {
            instance = new DataLocalManager();
        }
        return instance;
    }

    public static void setFirstInstalled(boolean isFirst) {
        DataLocalManager.getInstance().mySharedPreferences.putBooleanValue(PRE_FIRST_INSTALL, isFirst);
    }

    public static boolean getFirstInstalled() {
        return DataLocalManager.getInstance().mySharedPreferences.getBooleanValue(PRE_FIRST_INSTALL);
    }

    public static void setRememberMe(boolean isRememberMe) {
        DataLocalManager.getInstance().mySharedPreferences.putBooleanValue(PRE_FIRST_LOGIN, isRememberMe);
    }

    public static boolean getRememberMe() {
        return DataLocalManager.getInstance().mySharedPreferences.getBooleanValue(PRE_FIRST_LOGIN);
    }

    public static void setNameUsers(Set<String> nameUsers) {
        DataLocalManager.getInstance().mySharedPreferences.putStringSetValue(PRE_USER_NAME, nameUsers);
    }

    public static Set<String> getNameUsers() {
        return DataLocalManager.getInstance().mySharedPreferences.getStringSetValue(PRE_USER_NAME);
    }

    public static void setUser(User user) {
        Gson gson = new Gson();
        String strJsonUser = gson.toJson(user);
        DataLocalManager.getInstance().mySharedPreferences.putStringValue(PRE_OBJECT_USER, strJsonUser);
    }

    public static User getUser() {
        String strJsonUser = DataLocalManager.getInstance().mySharedPreferences.getStringValue(PRE_OBJECT_USER);
        // convert to string to object user
        Gson gson = new Gson();
        User user = gson.fromJson(strJsonUser, User.class);
        return user;
    }

}
