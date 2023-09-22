NAME = fixed

CC = clang++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

OBJS = ${SRCS:.cpp=.o}

${NAME} : ${OBJS}
	$(CC) $(WFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean all
