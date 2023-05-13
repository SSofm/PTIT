package com.sang.shoeapp.api;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.sang.shoeapp.model.Cart;
import com.sang.shoeapp.model.Invoice;
import com.sang.shoeapp.model.Product;
import com.sang.shoeapp.value_objects.CartId;
import com.sang.shoeapp.value_objects.UpdateUserProfile;
import com.sang.shoeapp.value_objects.UserRequest;
import com.sang.shoeapp.value_objects.UserRespone;

import java.util.List;
import java.util.Observable;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.DELETE;
import retrofit2.http.GET;
import retrofit2.http.HTTP;
import retrofit2.http.PATCH;
import retrofit2.http.POST;
import retrofit2.http.Path;
import retrofit2.http.Query;

public interface ShoeService {
    // create new user
    @POST("user/create-new-user")
    Call<UserRespone> signUp(@Body UserRequest body);

    // sign in
    @POST("auth/signin")
    Call<UserRespone> signIn(@Body UserRequest body);

    // update user
    @PATCH("user/{id}")
    Call<UpdateUserProfile> updateProfile(@Path("id") int userId, @Body UserRequest body);

    @GET("product")
    Call<List<Product>> getListProducts();

    @GET("product/get-all-product-with-cover-image")
    Call<List<Product>> getListProductsWithCoverImage();


    //    {{URL}}/cart/get-all-product-in-cart/1
    @GET("cart/get-all-product-in-cart/{id}")
//    Call<List<Cart>> getListItemsInCart(@Path("id") int cartId);
    Call<List<Product>> getListItemsInCart(@Path("id") int cartId);


    @GET("product/get-all-products-by-brand/{brandName}")
    Call<List<Product>> getAllProductsByBrand(@Path("brandName") String brandName);

    @POST("invoice/create-new-invoice/{userId}")
    Call<Invoice> createNewInvoice(@Path("userId") int userId);


//    @DELETE("cart/remove-product-from-cart/{productId}")
    @HTTP(method = "DELETE", path = "/cart/remove-product-from-cart/{productId}", hasBody = true)
    Call<Cart> removeProductFromCart(@Body CartId cart, @Path("productId") int productId);



    @DELETE("cart/remove-product-from-cart")
    Call<Cart> removeAllProductsInCart();

    @POST("cart/add-products-into-cart/{productId}")
    Call<Cart> addProductIntoCart(@Body CartId cart, @Path("productId") int productId);
}


