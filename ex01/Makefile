NAME		= 	phonebook

CXX			= 	c++ -Wall -Wextra -Werror -std=c++98

SRCS		=	Contact.cpp			\
				Phonebook.cpp		\
				PhonebookUtils.cpp	\
				Main.cpp			\

OBJS		= 	$(SRCS:.cpp=.o)

RM			= 	rm -f

$(NAME)		:	${OBJS}
				${CXX} $(OBJS) -o $(NAME)

all			:	$(NAME)
    
fclean		:	clean
				$(RM) $(NAME)
    
clean		:
				$(RM) $(OBJS) $(OBJS_B)
    
re			:	fclean all

.PHONY		:	all clean fclean re