#include "TinyJS/TinyJS.h"


class MyNativeClass {
public:
   void test() {
     printf("NativeClass test function.\r\n");
   }
};


class MyClass {
  static void destroy(void* p) {
    delete (MyNativeClass*)p;
  }

  static void constructor(CScriptVar* var, void *userData) {
    void* nativeClass = new MyNativeClass();
    var->setPoint(nativeClass, destroy, true);
  }

  static void test(CScriptVar* var, void *userData) {
    MyNativeClass* cls = (MyNativeClass*)var->getPoint();
    cls->test();
  }


public:
  static void registerFunctions(CTinyJS* tinyJS) {
    CScriptVar* cls = new CScriptVar(TINYJS_BLANK_DATA, SCRIPTVAR_OBJECT);
    cls->setNativeConstructor(constructor, NULL);
    tinyJS->addClass("MyClass", cls);

    tinyJS->addNative("function MyClass.test()", test, 0);
  }
};


int main(int argc, char** argv) {

  while(true) { //Don't be scared, just for memory test:P.
    CTinyJS tinyJS;

    MyClass::registerFunctions(&tinyJS);

    tinyJS.execute("var a = new MyClass(); a.test();");
  }

  return 0;
}
