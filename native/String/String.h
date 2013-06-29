#ifndef JSM_STRING
#define JSM_STRING

#include "../../TinyJS/TinyJS.h"

namespace JSM {

class String {
	static void indexOf(CScriptVar *c, void *);

	static void substring(CScriptVar *c, void *);

	static void charAt(CScriptVar *c, void *);

	static void charCodeAt(CScriptVar *c, void *);

	static void split(CScriptVar *c, void *);

	static void fromCharCode(CScriptVar *c, void *);

public:
  static void registerFunctions(CTinyJS* tinyJS);
};

};

#endif
