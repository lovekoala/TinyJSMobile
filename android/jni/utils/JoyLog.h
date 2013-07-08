/**
 * The Joy Log Helper Class
 * @author zhipeng.zhangzp
 */
#ifndef __JOYLOG_H__
#define __JOYLOG_H__
class JoyLog {
public:
	enum JoyLogLevel{
		VERBOSE, DEBUG, INFO, WARNING, ERROR
	};
	__attribute__((visibility("hidden"))) static void v(char *tag,char *msg,...);
	__attribute__((visibility("hidden"))) static void e(char *tag,char *msg,...);
	__attribute__((visibility("hidden"))) static void d(char *tag,char *msg,...);
	__attribute__((visibility("hidden"))) static void i(char *tag,char *msg,...);
	__attribute__((visibility("hidden"))) static void w(char *tag,char *msg,...);
	__attribute__((visibility("hidden"))) static void close();
	__attribute__((visibility("hidden"))) static void open();
	__attribute__((visibility("hidden"))) static void setPrintLevel(JoyLogLevel printLevel);
private:
	__attribute__((visibility("hidden"))) static bool shouldPrint(JoyLogLevel printLevel);
	__attribute__((visibility("hidden"))) static JoyLogLevel sLogLevel;
	__attribute__((visibility("hidden"))) static bool sIsLogOn;
};
#endif
