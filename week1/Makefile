NAME	=	ppm_test

PPM		=	ppm_test.ppm

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	create_ppm.cpp

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