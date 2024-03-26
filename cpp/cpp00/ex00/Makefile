NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

CC = clang++

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.cpp.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.cpp=.o}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
