NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lmlx -lmlx_Linux -lXext -lX11
INLCUDE = -I ./include
SRCS = src/draw/draw.c src/error/error.c src/event/events_utils.c src/event/events.c src/event/player_move.c\
		src/map/check_goal.c src/map/check_map_data.c src/map/get_map_data.c src/map/map_utils.c src/map/map.c\
		src/main.c src/draw/init_window_image.c
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIB_PATH = ./mlx
MINILIB = $(MINILIB_PATH)/libmlx_Linux.a

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

.c.o :
	$(CC) -c $< -o $@ $(CFLAGS) $(INLCUDE)

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(MINILIB) :
	make -C $(MINILIB_PATH)

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	make clean -C $(MINILIB_PATH)
	@$(RM) $(NAME)

re : fclean all