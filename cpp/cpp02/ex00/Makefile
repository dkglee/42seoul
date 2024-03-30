NAME = fixed

CC = c++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror --std=c++98

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		Fixed.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

${NAME} : ${OBJS}
	$(CC) $(WFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean all
