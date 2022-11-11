##### variables #####

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx_Linux -lXext -lX11
SRCS = test.c
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIB_PATH = ./mlx
MINILIB = $(MINILIB_PATH)/libmlx_Linux.a


##### rules #####

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIB_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(NAME)

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(MINILIB) :
	make -C $(MINILIB_PATH)

clean :
	make clean -C $(LIBFT_PATH)
	make clean -C $(MINILIB_PATH)
	rm $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(MINILIB_PATH)
	rm $(NAME)

re : fclean all