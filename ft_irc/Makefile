NAME = ft_irc

CC = clang++

RM = rm -rf

WFLAGS = -Wall -Wextra -Werror

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		Server.cpp \
		./Implement/Channel/Channel.cpp \
		./Implement/Creator/Factory.cpp \
		./Implement/Operation/AuthOperation.cpp \
		./Implement/Operation/Invite.cpp \
		./Implement/Operation/Join.cpp \
		./Implement/Operation/Kick.cpp \
		./Implement/Operation/Message.cpp \
		./Implement/Operation/Mode.cpp \
		./Implement/Operation/Topic.cpp \
		./Implement/Parse/Parse.cpp \
		./Implement/Socket/Socket.cpp \
		./Implement/User/User.cpp

OBJS = ${SRCS:.cpp=.o}

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
