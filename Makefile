CC=gcc
OBJS=main.o \
     table.o \
     player.o

output: $(OBJS)
	$(CC) $? -o $@ && ./$@

main.o: main.c

table.o: table.c

player.o: player.c

clean:
	rm -rf *.o *.exe output
