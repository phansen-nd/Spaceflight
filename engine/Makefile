OBJS = engine.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

engine: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o engine

engine.o: engine.cpp vector.h
	$(CC) $(CFLAGS) engine.cpp

clean:
	\rm *.o *~ engine