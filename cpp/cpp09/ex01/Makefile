NAME = rpn

CC = clang++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		RPN.cpp

OBJS = ${SRCS:.cpp=.o}

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
