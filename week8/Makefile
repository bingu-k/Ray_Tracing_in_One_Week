NAME	=	diffuse

PPM		=	diffuse.ppm

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++17

SRCS	=	create_ppm.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o		:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	./$(NAME) > $(PPM)
	open $(PPM)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME) $(PPM)

re		:	fclean all