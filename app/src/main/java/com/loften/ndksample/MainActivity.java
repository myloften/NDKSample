package com.loften.ndksample;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView) findViewById(R.id.tv);
        int[] array =  JniTest.getIntArray(10);
        StringBuilder mValue = new StringBuilder();
        for (int i : array) {
            mValue.append(i);
            mValue.append(",");
        }
        mValue.deleteCharAt(mValue.length()-1);
        tv.setText("["+mValue+"]");
    }


}
