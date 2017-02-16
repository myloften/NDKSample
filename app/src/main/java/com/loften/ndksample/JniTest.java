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

    //排序
    public static native void sortIntArray(int[] array);

    //C++中创建bean
    public native Bean creatBean(String msg,int what);

    //C++解析java对象
    public native String getBeanString(Bean bean);

    //C++修改对象属性值
    public native void ModifyBean(Bean bean);
}
