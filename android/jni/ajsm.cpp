/*
 * The Entry of the Jni
 * @author zhipeng.zhangzp
 *
 */
#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "env.h"
#include "utils/JoyLog.h"
#include "JNIRegisteredMethods.h"
using namespace JSM;

static void registerProxy(JNIEnv *env, jobject thiz, jobject target, jint order) {
	jclass cls = env->GetObjectClass(target);
	env->RegisterNatives(cls, g_mds[order].list, g_mds[order].num);
}

static void runJS(JNIEnv *env, jobject thiz, jobject context, jbyteArray data) {
	const char * jsText = (char *) env->GetByteArrayElements(data, NULL);
	try {
		Env::getInstance(context, env)->tinyJS->execute(jsText);
	} catch (CScriptException *e) {
		JoyLog::d("TinyJSAndroid","ERROR: %s\n", e->text.c_str());
	}
	env->ReleaseByteArrayElements(data, (signed char *) jsText, JNI_ABORT);
}

static const JNINativeMethod s_helper[] = { { "runJS",
		"(Landroid/content/Context;[B)V", (void *) runJS },
//	{ "registerJNI", "(Ljava/lang/Object;I)V", (void *) registerProxy }
		};

static int registerNativeMethods(JNIEnv* env, const char* className,
		JNINativeMethod* gMethods, int numMethods) {
	jclass clazz;
	clazz = env->FindClass(className);
	if (clazz == NULL) {
		return JNI_FALSE;
	}
	if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
		return JNI_FALSE;
	}

	return JNI_TRUE;
}

/*
 * Register native methods for all classes we know about.
 */
static int registerNatives(JNIEnv* env) {
	if (!registerNativeMethods(env, "com/taobao/joyapi/jsnative/JSBinder",
			(JNINativeMethod *) s_helper,
			sizeof(s_helper) / sizeof(s_helper[0])))
		return JNI_FALSE;

	return JNI_TRUE;
}

/*
 * Bind the native codes to the java environment
 *
 * Returns the JNI version on success, -1 on failure.
 */JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return -1;
	}

	if (!registerNatives(env)) {
		return -1;
	}
	/* success -- return valid version number */
	result = JNI_VERSION_1_4;
	Env::javaVM = vm;
	return result;
}
