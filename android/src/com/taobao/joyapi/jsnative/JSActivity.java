package com.taobao.joyapi.jsnative;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

public class JSActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_js);
	}
	
	
	public static void startActivity(Context context) {
		Intent intent = new Intent(context,JSActivity.class);
		intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		context.startActivity(intent);
	}
}
