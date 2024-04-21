NAME = clap

CC = c++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

OBJS = ${SRCS:.cpp=.o}

.o : .cpp
	$(CC) $(CFLAGS) -c $< -o $@

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : ${NAME}

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re
