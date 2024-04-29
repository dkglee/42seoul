NAME = animal

CC = c++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror -std=c++98

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : ${NAME}

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
