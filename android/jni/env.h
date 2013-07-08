/**
 * Store the global js environment params
 * @author zhipeng.zhangzp
 */
#ifndef __ENV_ANDROID_JSM_H__
#define __ENV_ANDROID_JSM_H__
#include <TinyJS/TinyJS.h>
#include <jni.h>
#include "android/app/Activity.h"
namespace JSM {
struct Env {
public:
	static Env* spEnv;
	static JavaVM *javaVM;
	CTinyJS * tinyJS;
	jobject context;

	static Env *getInstance(jobject context,JNIEnv *jniEnv) {
		if(spEnv == NULL) {
			spEnv = new Env(context);
		}
		return spEnv;
	}

	void getJNIEnv(JNIEnv **pjniEnv) {
		javaVM->GetEnv((void **)pjniEnv,JNI_VERSION_1_4);
		if(*pjniEnv == NULL) {
			javaVM->AttachCurrentThread(pjniEnv,NULL);
		}
	}

	Env(jobject context);

	~Env();
};
};
#endif
