/**
 * The implementation of binder activity
 * @author zhipeng.zhangzp
 */
#ifndef __ACTIVITY_H_
#define __ACTIVITY_H_
#include "TinyJS/TinyJS.h"
namespace JSM {
class ActivityNativeClass {
public:
   void startActivity();
};


class Activity {
  static void destroy(void* p) {
    delete (ActivityNativeClass*)p;
  }

  static void constructor(CScriptVar* var, void *userData);

  static void startActivity(CScriptVar* var, void *userData) {
    ActivityNativeClass* cls = (ActivityNativeClass*)var->getPoint();
    cls->startActivity();
  }

public:
  static void registerFunctions(CTinyJS* tinyJS) {
    CScriptVar* cls = new CScriptVar(TINYJS_BLANK_DATA, SCRIPTVAR_OBJECT);
    cls->setNativeConstructor(constructor, NULL);
    tinyJS->addClass("Activity", cls);
    tinyJS->addNative("function Activity.startActivity()", startActivity, 0);
  }
};
};
#endif
