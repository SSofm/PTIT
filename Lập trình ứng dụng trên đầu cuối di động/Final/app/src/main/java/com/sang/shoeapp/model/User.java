package com.sang.shoeapp.model;

public class User {
    private int id;
    private String username;
    private String email;
    private int cartId;

    public User(int id, String username, String email, int cartId) {
        this.id = id;
        this.username = username;
        this.email = email;
        this.cartId = cartId;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getCartId() {
        return cartId;
    }

    public void setCartId(int cartId) {
        this.cartId = cartId;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", email='" + email + '\'' +
                ", cartId=" + cartId +
                '}';
    }
}
