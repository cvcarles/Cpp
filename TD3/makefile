CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC = testcomplexe.cpp complexe.cpp
PROG = test
OBJS = $(SRC:.cpp=.o)
.SUFFIXES : .cpp .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC)	-o $@ $^ $(LDFLAGS)

test.o: complexe.hpp
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
