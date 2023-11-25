CC=gcc
OBJS=main.o \
     table.o \
     player.o \
     turn.o

output: $(OBJS)
	$(CC) $? -o $@ && ./$@

main.o: main.c

table.o: table.c

player.o: player.c

turn.o: turn.c

clean:
	rm -rf *.o *.exe
