CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = exo1.cpp complexe.cpp
PROG = exo1
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

exo1.o: complexe.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)