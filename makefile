CC := g++
CFLAGS := -g -Wall
TARGET := SignInMan


default: all

all: main.o  common.h 
	$(CC) $(CFLAGS) -o $(TARGET)  main.o 

main.o: main.cpp common.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) SignInMan. *.0 *~

