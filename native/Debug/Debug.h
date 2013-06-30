#ifndef JSM_DEBUG
#define JSM_DEBUG

#include "../../TinyJS/TinyJS.h"

namespace JSM {

class Debug {
  static void print(CScriptVar *v, void *userdata) {
    printf("%s\n", v->getParameter("text")->getString().c_str());
  }

  static void dump(CScriptVar *v, void *userdata) {
    CTinyJS *js = (CTinyJS*)userdata;
    js->root->trace("> ");
  }

public:
  static void registerFunctions(CTinyJS* js) {
    js->addNative("function print(text)", &Debug::print, 0);
    js->addNative("function Debug.print(text)", &Debug::print, 0);
    js->addNative("function Debug.dump()", &Debug::dump, js);
  }
};

};

#endif
