NAME		= 	PhoneBook

CXX			= 	c++ -Wall -Wextra -Werror -std=c++98

SRCS		=	Contact.cpp			\
				PhoneBook.cpp		\
				PhoneBookUtils.cpp	\
				main.cpp			\

OBJS		= 	$(SRCS:.cpp=.o)

RM			= 	rm -f

$(NAME)		:	${OBJS}
				${CXX} $(OBJS) -o $(NAME)

all			:	$(NAME)
    
fclean		:	clean
				$(RM) $(NAME)
    
clean		:
				$(RM) $(OBJS)
    
re			:	fclean all

.PHONY		:	all clean fclean re