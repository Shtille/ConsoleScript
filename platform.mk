# Platform-specific defines
STATIC_LIB_EXT = .a
AR = ar rcs
ifeq ($(OS),Windows_NT)
	#CCFLAGS += -D WIN32
	MAKE := mingw32-make.exe
	LDFLAGS = -s -shared
	CC = gcc
	CCP = g++
	SHARED_LIB_EXT = .so
else
	MAKE := make
	LDFLAGS = -shared -fPIC
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		#CCFLAGS += -D LINUX
		CC = gcc
		CCP = g++
		SHARED_LIB_EXT = .so
	endif
	ifeq ($(UNAME_S),Darwin)
		#CCFLAGS += -D OSX
		CC = clang
		CCP = clang++
		SHARED_LIB_EXT = .dylib
	endif
endif
