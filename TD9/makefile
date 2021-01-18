CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = exo.cpp
PROG = exo
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

exo.o: enseignant.hpp personne.hpp salarie.hpp animal.hpp herbivore.hpp carnivore.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)