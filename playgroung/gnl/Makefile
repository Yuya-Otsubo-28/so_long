NAME = gnl
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)