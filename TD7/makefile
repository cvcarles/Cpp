CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = exo.cpp rectangle.cpp carre.cpp cercle.cpp ellipse.cpp figure.cpp
PROG = exo
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

fctgen.o: rectangle.hpp carre.hpp cercle.hpp ellipse.hpp figure.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)