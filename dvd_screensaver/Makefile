PROGRAM = dvd_screensaver
OBJS=main.o dvd.o screen.o
CC = gcc

all: ${OBJS}
	${CC} -g ${OBJS} -lraylib -o ${PROGRAM}

run: ${PROGRAM}
	./${PROGRAM} ${ARGS}

clean:
	rm ${OBJS} ${PROGRAM}
