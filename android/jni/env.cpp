/**
 * Store the global js environment params
 * @author zhipeng.zhangzp
 */
#include <env.h>
#include "android/app/Activity.h"
using namespace JSM;

Env* Env::spEnv = 0;
JavaVM* Env::javaVM = 0;
Env::Env(jobject context) {
	JNIEnv *jniEnv;
	getJNIEnv(&jniEnv);
	tinyJS = new CTinyJS();
	Activity::registerFunctions(tinyJS);
	this->context = jniEnv->NewGlobalRef(context);
}

Env::~Env(){
	JNIEnv *jniEnv;
    getJNIEnv(&jniEnv);
    jniEnv->DeleteGlobalRef(context);
    delete tinyJS;
}
