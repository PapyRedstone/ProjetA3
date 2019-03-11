CFLAGS = -g -Wall -pedantic
LDFLAGS = 

SRC = $(wildcard src/*.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

all: ProjetA3.out

remake: clean ProjetA3.out

ProjetA3.out : $(OBJ)
	gcc obj/* $(LDFLAGS) -o $@ 

obj/%.o: src/%.c
	gcc -c -Iinclude $(CFLAGS) -o $@ $<

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f
