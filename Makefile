EXECUTABLE_NAME=output
COMPILER=gcc
FILES_TO_COMPILE=main.c \
		table.c \
		player.c \
		turn.c

main: $(FILES_TO_COMPILE)
	$(COMPILER) $? -o $(EXECUTABLE_NAME) && ./$(EXECUTABLE_NAME)
