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

exo.o: complexe.hpp PileChainee.hpp noeud.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)