CFLAGS = -g -Wall -pedantic
LDFLAGS = ./ftd2xx.lib

SRC = $(wildcard *.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

all: ProjetA3.exe

remake: clean ProjetA3.exe

ProjetA3.exe : $(OBJ)
	gcc obj/* $(LDFLAGS) $(CFLAGS) -o $@ 

obj/%.o: %.c
	gcc -c -I. $(CFLAGS) -o $@ $<

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f
