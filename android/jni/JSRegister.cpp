/*
 * The javascript classes & methods register helper
 *
 *  @author zhipeng.zhangzp
 */
#include "JSRegister.h"
using namespace JSM;

list<JSRegisterMethod> JSRegister::jsRegisterMethods;

void JSRegister::addJSRegisterMethods(JSRegisterMethod jsRegisterMethod) {
	jsRegisterMethods.push_back(jsRegisterMethod);
}

void JSRegister::registers(CTinyJS *tinyJS) {
	for(list<JSRegisterMethod>::iterator it = jsRegisterMethods.begin(); it != jsRegisterMethods.end(); it++) {
		(*it)(tinyJS);
	}
}
