# Basic Makefile structure
# ========================
# target: dependencies
# 		system command
# ========================

#~ Advanced generic makefile
#~ =============================================
#~ CC=g++
#~ CFLAGS=-c -Wall
#~ LDFLAGS=
#~ SOURCES=main.cpp hello.cpp factorial.cpp
#~ OBJECTS=$(SOURCES:.cpp=.o)
#~ EXECUTABLE=hello

#~ all: $(SOURCES) $(EXECUTABLE)
	
#~ $(EXECUTABLE): $(OBJECTS) 
#~     $(CC) $(LDFLAGS) $(OBJECTS) -o $@

#~ .cpp.o:
#~     $(CC) $(CFLAGS) $< -o $@
#~ =============================================

# Variables
CC=g++
CFLAGS= -Wall -Iinclude -std=c++11
#-std=c++11

#~ all: main.cpp
#~ 	g++ -Wall -Incurses -Iinclude -std=c++11 -o main main.cpp
#~ 	g++ main.cpp -Wall -Iinclude -std=c++11 -o main

all: busTest

#~ busTest: busTest.o messageBus.o 
#~ 	$(CC) busTest.o messageBus.o -o busTest

#~ busTest.o: busTest.cpp
#~ 	$(CC) $(CFLAGS) busTest.cpp

#~ messageBus.o: messageBus.cpp
#~ 	$(CC) $(CFLAGS) messageBus.cpp

busTest: busTest.cpp messageBus.cpp 
	$(CC) $(CFLAGS) busTest.cpp messageBus.cpp -o ./bin/busTest

clean:
	rm ./bin/busTest
