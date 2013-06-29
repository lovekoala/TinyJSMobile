#include "TinyJS/TinyJS.h"
#include "native/Debug/Debug.h"
#include "native/String/String.h"
#include "native/Array/Array.h"

int main(int argc, char** argv) {
	CTinyJS tinyJS;

  JSM::Debug::registerFunctions(&tinyJS);
  JSM::String::registerFunctions(&tinyJS);
  JSM::Array::registerFunctions(&tinyJS);

	tinyJS.execute("var _terminated = 0; function exit() { _terminated = 1; } ");

	while(tinyJS.evaluate("_terminated") == "0") {
    char buffer[2048];
    fgets ( buffer, sizeof(buffer), stdin );

    try {
      tinyJS.execute(buffer);
    } catch (CScriptException *e) {
      printf("ERROR: %s\n", e->text.c_str());
    }
  }
}
