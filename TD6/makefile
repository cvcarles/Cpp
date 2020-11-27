CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = fctgen.cpp rectangle.cpp
PROG = fctgen
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

fctgen.o: rectangle.hpp pileTableau.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)