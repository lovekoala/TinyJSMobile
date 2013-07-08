/**
 * The Activity binder
 *
 * @author zhipeng.zhangzp
 */
#include "Activity.h"
#include "env.h"
#include "utils/JoyLog.h"
using namespace JSM;
void ActivityNativeClass::startActivity() {
     printf("OK activity started.\r\n");
}

void Activity::constructor(CScriptVar* var, void *userData) {
    void* nativeClass = new ActivityNativeClass();
    var->setPoint(nativeClass, destroy, true);
   jobject context = Env::spEnv->context;
    JNIEnv *jniEnv;
    Env::spEnv->getJNIEnv(&jniEnv);
    jclass jsActivity = jniEnv->FindClass("com/taobao/joyapi/jsnative/JSActivity");
    jmethodID jsStartActivity = jniEnv->GetStaticMethodID(jsActivity, "startActivity","(Landroid/content/Context;)V");
    jniEnv->CallStaticVoidMethod(jsActivity, jsStartActivity, context);
}
