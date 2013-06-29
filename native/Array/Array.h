#ifndef JSM_ARRAY
#define JSM_ARRAY

#include "../../TinyJS/TinyJS.h"

namespace JSM {

class Array {
  static void contains(CScriptVar *c, void *data);

  static void remove(CScriptVar *c, void *data);

  static void join(CScriptVar *c, void *data);

public:
  static void registerFunctions(CTinyJS* tinyJS);
};

};

#endif
