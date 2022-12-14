NAME = gnl.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ../include

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
