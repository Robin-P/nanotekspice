NAME		=	nanotekspice

CC		=	g++

RM		=	rm -f

SRCS		=	srcs/main.cpp				\
			srcs/game/launch.cpp			\
			srcs/game/setState.cpp			\
			srcs/game/dump.cpp			\
			srcs/game/commands.cpp			\
			srcs/class/Game/Compute.cpp		\
			srcs/class/Game/Circuit.cpp		\
			srcs/class/Component/Component.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-I./header/class/Game/			\
			-I./header/class/Component/		\
			-I./header/class/Exception		\
			-I./header/include/			\
			-I./header/interface/

CPPFLAGS+=		-W -Wall -Wextra -g3

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
