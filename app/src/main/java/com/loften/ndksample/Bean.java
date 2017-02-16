package com.loften.ndksample;

/**
 * Created by asus on 2017/2/16.
 */

public class Bean {
    private String msg;
    private int what;

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public int getWhat() {
        return what;
    }

    public void setWhat(int what) {
        this.what = what;
    }

    public Bean(String msg, int what) {
        this.msg = msg;
        this.what = what;
    }


}
