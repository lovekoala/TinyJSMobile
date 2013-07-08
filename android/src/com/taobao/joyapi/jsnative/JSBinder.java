package com.taobao.joyapi.jsnative;

import android.content.Context;
import android.content.Intent;

/**
 * The JSBinder Helper class
 * @author zhipeng.zhangzp
 *
 */
public class JSBinder {
	
	public static JSBinder getInstance() {
		if(sJSBinder == null) {
			sJSBinder = Init.sJSBinder;
		}
		return sJSBinder;
	}
	
	public static void init(Context context) {
		sContext = context;
	}
	
	private JSBinder(){
			System.loadLibrary("jsm");
	}
	
	public static class Init {
		public static JSBinder sJSBinder = new JSBinder();
	}
	
	public void runJS(byte[] s) {
		runJS(sContext,s);
	}
	
	public native void runJS(Context context,byte[] s);
	private static JSBinder sJSBinder;
	private static Context sContext;
}
