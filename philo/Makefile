NAME = philo

SRCS_FILES = fork.c init.c main.c monitor.c philo_action.c print_action.c thread.c time.c utils.c
SRCS = $(addprefix ./src/, $(SRCS_FILES))
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
#CFLAGS = -Wall -Wextra -Werror -pthread

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