NAME	=	vec3_test

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	vec3_test.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o		:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all