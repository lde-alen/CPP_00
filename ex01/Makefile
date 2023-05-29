NAME		= 	phonebook

SRCS		=	contact.cpp			\
				phonebook.cpp		\
				phonebook_utils.cpp	\
				main.cpp			\

OBJS		= 	$(SRCS:.cpp=.o)

RM			= 	rm -f

FLAGS		= 	-Wall -Wextra -Werror -std=c++98

COMPILER	= 	c++

$(NAME)		:	${OBJS}
				${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)

all			:	$(NAME)
    
fclean		:	clean
				$(RM) $(NAME)
    
clean		:
				$(RM) $(OBJS) $(OBJS_B)
    
re			:	fclean all

.PHONY		:	all clean fclean re