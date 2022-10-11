OBJS	= main.o
SOURCE	= main.cc
HEADER	= dynamic_array.h main.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cc
	$(CC) $(FLAGS) main.cc -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
