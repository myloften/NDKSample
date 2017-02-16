package com.loften.ndksample;

import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    private TextView mTv1;
    private TextView mTv2;
    private TextView mTv3;
    private TextView mTv4;
    private TextView mTv5;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initViews();
        initDatas();
    }

    private void initDatas() {
        int[] array =  JniTest.getIntArray(10);
        StringBuilder mValue1 = intArrayToString(array);
        mTv1.setText("["+mValue1+"]");
        JniTest.sortIntArray(array);
        StringBuilder mValue2 = intArrayToString(array);
        mTv2.setText("["+mValue2+"]");
        JniTest jniTest = new JniTest();
        Bean bean = jniTest.creatBean("this is a new bean", 1);
        mTv3.setText(bean.getMsg()+":"+bean.getWhat());
        mTv4.setText(jniTest.getBeanString(bean));
        jniTest.ModifyBean(bean);
        mTv5.setText(bean.getMsg()+":"+bean.getWhat());

        Test(1000);
    }

    private void Test(int i) {
        long startTime = System.currentTimeMillis();
        for (int i1 = 0; i1 < i; i1++) {
            new Bean("123",i1);
        }
        long endTime = System.currentTimeMillis();
        Log.e("Java","Java new "+i+"s waste "+(endTime-startTime)+"ms");

        JniTest jniTest = new JniTest();
        startTime = System.currentTimeMillis();
        for (int i2 = 0; i2 < i; i2++) {
            jniTest.creatBean("123",i2);
        }
        endTime = System.currentTimeMillis();
        Log.e("C++","C++ new "+i+"s waste "+(endTime-startTime)+"ms");

    }


    @NonNull
    private StringBuilder intArrayToString(int[] array) {
        StringBuilder mValue = new StringBuilder();
        for (int i : array) {
            mValue.append(i);
            mValue.append(",");
        }
        mValue.deleteCharAt(mValue.length()-1);
        return mValue;
    }

    private void initViews() {
        mTv1 = (TextView) findViewById(R.id.tv1);
        mTv2 = (TextView) findViewById(R.id.tv2);
        mTv3 = (TextView) findViewById(R.id.tv3);
        mTv4 = (TextView) findViewById(R.id.tv4);
        mTv5 = (TextView) findViewById(R.id.tv5);
    }


}
