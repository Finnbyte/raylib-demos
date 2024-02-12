PROGRAM = dvd_screensaver
OBJS=main.o screen.o
CC = gcc

all: ${OBJS}
	${CC} ${OBJS} -lraylib -o ${PROGRAM}

run: ${PROGRAM}
	./${PROGRAM} ${ARGS}

clean:
	rm ${OBJS} ${PROGRAM}
