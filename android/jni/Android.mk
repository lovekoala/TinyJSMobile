LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
ALLFILES = $(shell find . -name "*.cpp") 
SUBFILES = $(subst jni/,,$(ALLFILES))
INCLUDE_PATH = $(shell cd .. && pwd)
INCLUDE_PATH2 = $(shell cd jni && pwd)
LOCAL_CFLAGS += -fexceptions -I$(INCLUDE_PATH) -I$(INCLUDE_PATH2)
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
LOCAL_MODULE    := jsm
LOCAL_SRC_FILES := ../../jsm.cpp \
      ../../TinyJS/TinyJS.cpp \
      ../../native/String/String.cpp \
      ../../native/Array/Array.cpp  \
      $(SUBFILES)
include $(BUILD_SHARED_LIBRARY)

