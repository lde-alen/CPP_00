NAME		= 	megaphone

SRCS		=	megaphone.cpp

OBJS		= 	$(SRCS:.cpp=.o)

RM			= 	rm -f

FLAGS		= 	-Wall -Wextra -Werror -std=c++98

COMPILER	= 	clang++

$(NAME)		:	${OBJS}
				${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)

all			:	$(NAME)
    
fclean		:	clean
				$(RM) $(NAME)
    
clean		:
				$(RM) $(OBJS) $(OBJS_B)
    
re			:	fclean all

.PHONY		:	all clean fclean re