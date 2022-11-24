CC = g++
CFLAGS = -I.

SRCS = $(wildcard *.cc)
OBJS = $(SRCS:.cc=.o)

all:main

main:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS):%.o:%.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main