CC=gcc
OBJS=main.o \
     table.o \
     player.o
EXENAME=program

$(EXENAME): $(OBJS)
		$(CC) $? -o $@ && ./$@

main.o: main.c

table.o: table.c

player.o: player.c

clean:
		rm -rf *.o *.exe $(EXENAME)
