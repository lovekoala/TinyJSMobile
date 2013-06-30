CFLAG = -g
SRCS = jsm.cpp \
	  TinyJS/TinyJS.cpp \
	  native/String/String.cpp \
	  native/Array/Array.cpp 

TARGET = jsm
all:
	g++ ${CFLAG} -o ${TARGET} ${SRCS}

clean:
	rm -fr jsm *.o jsm.dSYM

