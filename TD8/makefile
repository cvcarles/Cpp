CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = exo.cpp complexe.cpp
PROG = exo
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

fctgen.o: MonException1.hpp MonException2.hpp complexe.hpp IndexException.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)