package com.taobao.joyapi.jsnative;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

	private static String JS_STRING = "var a=new Activity();";
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		JSBinder.init(getApplicationContext());
		setTextView(R.id.js_text, JS_STRING);
		mJSText = (EditText)findViewById(R.id.js_text);
	}
	
	private void setTextView(int resId, String text) {
		TextView textView = (TextView)findViewById(resId);
		if(textView != null) {
			textView.setText(text);
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	public void onRunJSClicked(View view) {
		JSBinder.getInstance().runJS(mJSText.getText().toString().getBytes());
	}

	private EditText mJSText;
}
