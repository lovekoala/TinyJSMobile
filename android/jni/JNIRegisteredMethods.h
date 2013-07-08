/**
 * The JNI register methods helper
 * @author zhipeng.zhangzp
 */
#ifndef __REGISTERMETHODS_H__
#define __REGISTERMETHODS_H__
#include <jni.h>
#define SIG_METHODS 0
typedef JNINativeMethod *MethodPtr;
struct JoyMethods {
	MethodPtr list;
	int num;
};
__attribute__((visibility("hidden"))) extern const JoyMethods g_sg_md;
__attribute__((visibility("hidden"))) extern const JoyMethods g_es_md;
__attribute__((visibility("hidden"))) extern JoyMethods g_mds[];
#endif
