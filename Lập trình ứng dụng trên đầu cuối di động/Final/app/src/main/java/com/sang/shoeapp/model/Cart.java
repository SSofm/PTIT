package com.sang.shoeapp.model;

import java.io.Serializable;
import java.util.List;

public class Cart implements Serializable {
    private int id;
    private List<Product> products;

    public Cart(int id, List<Product> products) {
        this.id = id;
        this.products = products;
    }

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
}

