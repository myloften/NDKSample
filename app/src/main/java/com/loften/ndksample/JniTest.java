package com.loften.ndksample;

/**
 * Created by asus on 2017/2/15.
 */

public class JniTest {
    static {
        System.loadLibrary("myjni");
    }

    public static native String combine(String a, String b);
}
