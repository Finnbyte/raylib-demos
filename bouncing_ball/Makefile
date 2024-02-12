PROGRAM = bouncing_ball
OBJS=main.o ball.o
CC = gcc

all: $(OBJS)
	${CC} ${OBJS} -lraylib -o ${PROGRAM}

run: ${PROGRAM_NAME}
	./${PROGRAM_NAME} ${ARGS}

clean:
	rm ${OBJS} ${PROGRAM}
