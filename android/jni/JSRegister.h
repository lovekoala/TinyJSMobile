/*
 * The javascript classes & methods register helper
 *
 *  @author zhipeng.zhangzp
 */
#include <list>
#include <jni.h>
#include "TinyJS/TinyJS.h"

using namespace std;
namespace JSM {
typedef void (*JSRegisterMethod)(CTinyJS*);

class JSRegister {
	static list<JSRegisterMethod> jsRegisterMethods;
	static void addJSRegisterMethods(JSRegisterMethod jsRegisterMethod);
	static void registers(CTinyJS *tinyJS);
};
};
