CC := g++

CFLAGS := -Wall --std=c++11

HDRS := AbstractHex.h HexVector.h HexArray1D.h

SRCS := main.cpp AbstractHex.cpp HexVector.cpp HexArray1D.cpp
 
OBJS := $(SRCS:.c=.o)

EXEC := run

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
