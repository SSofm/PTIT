package com.sang.shoeapp.model;

import java.util.List;

public class Invoice {
    private int id;
    private List<Product> products;
    private User user;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Invoice(int id, List<Product> products, User user) {
        this.id = id;
        this.products = products;
        this.user = user;
    }
}
