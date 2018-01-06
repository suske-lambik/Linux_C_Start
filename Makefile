all: CardGame HelloWorld MyCat LoadTest GpioMgr Test CardGame AsciiTable FctCallback MyInotify

CC=gcc
CFLAGS= -Wall -Iinclude

CardGame: CardGame.c
	$(CC) $(CFLAGS) CardGame.c -o CardGame

HelloWorld: hello_world.c
	$(CC) $(CFLAGS) hello_world.c -o HelloWorld

MyCat: MyCat.c
	$(CC) $(CFLAGS) MyCat.c -o MyCat

LoadTest: load.c
	$(CC) $(CFLAGS) load.c -o LoadTest

GpioMgr: MyGpioMgr.c MyStruct.h
	$(CC) $(CFLAGS) MyGpioMgr.c -o GpioMgr

AsciiTable: asciiTable.c
	$(CC) $(CFLAGS) asciiTable.c -o AsciiTable

FctCallback: FctCallback.c
	$(CC) $(CFLAGS) FctCallback.c -o FctCallback
	
MyInotify: MyInotify.c 
	$(CC) $(CFLAGS) MyInotify.c -o MyInotify
	
Test: test.c
	$(CC) $(CFLAGS) test.c -o Test -fno-stack-protector

# Basic Makefile structure
# ========================
# target: dependencies
# 		system command
# ========================

#~ Advanced generic makefile
#~ =============================================
#~ CC=gcc
#~ CFLAGS=-c -Wall
#~ LDFLAGS=-Iinclude	
#~ SOURCES=MyFirstSocket.c
#~ OBJECTS=$(SOURCES:.c=.o)
#~ EXECUTABLE=MyFirstSocket

#~ all: $(SOURCES) $(EXECUTABLE)
	
#~ $(EXECUTABLE): $(OBJECTS) 
#~     $(CC) $(LDFLAGS) $(OBJECTS) -o $@

#~ .cpp.o:
#~     $(CC) $(CFLAGS) $< -o $@
#~ =============================================

# Basic Makefile
#~ =============================================
#~ Variables
#~ CC=g++
#~ CFLAGS= -Wall -Iinclude -std=c++11

#~ all: busTest

#~ busTest: busTest.cpp messageBus.cpp 
#~ 	$(CC) $(CFLAGS) busTest.cpp messageBus.cpp -o ./bin/busTest

#~ clean:
#~ 	rm ./bin/busTest
#~ =============================================
