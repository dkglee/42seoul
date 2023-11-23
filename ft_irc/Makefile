NAME = ft_irc

CC = clang++
CXX = g++

RM = rm -rf

WFLAGS = -g

CFLAGS = ${WFLAGS}

SRCS = main.cpp \
		Server.cpp \
		./implement/Channel/Channel.cpp \
		./implement/String/Stringtool.cpp \
		./implement/Creator/Factory.cpp \
		./implement/Operation/IOperation.cpp \
		./implement/Operation/AuthOperation.cpp \
		./implement/Operation/Invite.cpp \
		./implement/Operation/Join.cpp \
		./implement/Operation/Kick.cpp \
		./implement/Operation/Message.cpp \
		./implement/Operation/Mode.cpp \
		./implement/Operation/Topic.cpp \
		./implement/Parse/Parse.cpp \
		./implement/Socket/Socket.cpp \
		./implement/User/User.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

${NAME} : ${OBJS}
	$(CC) -g $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
