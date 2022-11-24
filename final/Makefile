# Define Compiler
CXX = g++
# Define Compiler Flags
CXXFLAGS = -I.

# Define the source files in .cc format
SRCS = $(wildcard *.cc)
# Define the object files in .o format
OBJS = $(SRCS:.cc=.o)
all:main

main:$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS):%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main
