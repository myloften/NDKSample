package com.loften.ndksample;

/**
 * Created by asus on 2017/2/15.
 */

public class JniTest {
    static {
        System.loadLibrary("myjni");
    }

    //连接两字符串
    public static native String combine(String a, String b);

    //输入size后返回该大小数组
    public static native int[] getIntArray(int size);


}
