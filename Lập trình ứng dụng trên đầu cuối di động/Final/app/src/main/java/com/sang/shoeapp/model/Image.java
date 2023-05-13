package com.sang.shoeapp.model;

import java.io.Serializable;

public class Image implements Serializable {
    private int id;
    private String url;

    public Image(int id, String url) {
        this.id = id;
        this.url = url;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }
}
