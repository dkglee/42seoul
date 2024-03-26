NAME = account

CFLAGS = -Wall -Wextra -Werror

CC = clang++

SRCS = Account.cpp \
		test.cpp

OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.cpp=.o}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -g ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
