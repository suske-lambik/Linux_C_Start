CC=gcc
CFLAGS= -Wall -I../include
OUT=../bin/

all: $(OUT)CardGame $(OUT)HelloWorld $(OUT)MyCat $(OUT)LoadTest $(OUT)GpioMgr $(OUT)Test $(OUT)CardGame $(OUT)AsciiTable $(OUT)MyInotify $(OUT)SystemCall $(OUT)MyThreads

$(OUT)CardGame: CardGame.c
	$(CC) $(CFLAGS) CardGame.c -o $(OUT)CardGame

$(OUT)HelloWorld: hello_world.c
	$(CC) $(CFLAGS) hello_world.c -o $(OUT)HelloWorld

$(OUT)MyCat: MyCat.c
	$(CC) $(CFLAGS) MyCat.c -o $(OUT)MyCat

$(OUT)LoadTest: load.c
	$(CC) $(CFLAGS) load.c -o $(OUT)LoadTest

$(OUT)GpioMgr: MyGpioMgr.c MyStruct.h
	$(CC) $(CFLAGS) MyGpioMgr.c -o $(OUT)GpioMgr

$(OUT)AsciiTable: asciiTable.c
	$(CC) $(CFLAGS) asciiTable.c -o $(OUT)AsciiTable
	
$(OUT)MyInotify: MyInotify.c 
	$(CC) $(CFLAGS) MyInotify.c -o $(OUT)MyInotify
	
$(OUT)Test: test.c
	$(CC) $(CFLAGS) test.c -o $(OUT)Test -fno-stack-protector

$(OUT)SystemCall: SystemCall.c
	$(CC) $(CFLAGS) SystemCall.c -o $(OUT)SystemCall
	
$(OUT)MyThreads: MyThreads.c
	$(CC) $(CFLAGS) MyThreads.c -pthread -o $(OUT)MyThreads

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
