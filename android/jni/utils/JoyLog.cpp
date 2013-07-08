/**
 * The JoyLog Print Helper Class
 * @author zhipeng.zhangzp
 */
#include <android/log.h>
#include "JoyLog.h"
JoyLog::JoyLogLevel JoyLog::sLogLevel = VERBOSE;
bool JoyLog::sIsLogOn = true;

void JoyLog::close() {
	sIsLogOn = false;
}

void JoyLog::open() {
	sIsLogOn = true;
}

bool JoyLog::shouldPrint(JoyLog::JoyLogLevel level) {
	if (level < sLogLevel || !sIsLogOn) {
		return false;
	}
	return true;
}

void JoyLog::d(char *tag, char * msg, ...) {
	if (shouldPrint(DEBUG)) {
		va_list vaPtr;
		va_start(vaPtr, msg);
		__android_log_vprint(ANDROID_LOG_DEBUG, tag, msg, vaPtr);
		va_end(vaPtr);
	}
}

void JoyLog::e(char *tag, char *msg, ...) {
	if (shouldPrint(ERROR)) {
		va_list vaPtr;
		va_start(vaPtr, msg);
		__android_log_vprint(ANDROID_LOG_ERROR, tag, msg, vaPtr);
		va_end(vaPtr);
	}
}

void JoyLog::i(char *tag, char *msg, ...) {
	if (shouldPrint(INFO)) {
		va_list vaPtr;
		va_start(vaPtr, msg);
		__android_log_vprint(ANDROID_LOG_INFO, tag, msg, vaPtr);
		va_end(vaPtr);
	}
}

void JoyLog::v(char *tag, char *msg, ...) {
	if (shouldPrint(VERBOSE)) {
		va_list vaPtr;
		va_start(vaPtr, msg);
		__android_log_vprint(ANDROID_LOG_VERBOSE, tag, msg, vaPtr);
		va_end(vaPtr);
	}
}

void JoyLog::w(char *tag, char *msg, ...) {
	if (shouldPrint(WARNING)) {
		va_list vaPtr;
		va_start(vaPtr, msg);
		__android_log_vprint(ANDROID_LOG_WARN, tag, msg, vaPtr);
		va_end(vaPtr);
	}
}

void JoyLog::setPrintLevel(JoyLogLevel printLevel) {
	sLogLevel = printLevel;
}
