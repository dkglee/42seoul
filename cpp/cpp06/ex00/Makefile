NAME = cast

CC = c++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror -std=c++98

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		ScalarConverter.cpp

OBJS = ${SRCS:.cpp=.o}

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
