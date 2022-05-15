NAME = philo

SRCS = $(shell find "./src/" -name "*.c")
OBJS = ${SRCS:.c=.o}
FLAG = -fsanitize=thread
CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} $(FLAG) -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re