NAME = philo

SRCS = $(shell find "./src/" -name "*.c")
OBJS = ${SRCS:.c=.o}
#FLAG = -fsanitize=thread -g
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} $(FLAG) -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re