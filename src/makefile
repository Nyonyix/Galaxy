IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -ggdb -Wextra -Wall -fpic 

EXE=../bin/galaxy

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Star.hpp nyonLib.hpp json.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o Star.o nyonLib.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
