NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lmlx -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11 -lm
INLCUDE = -I ./include -I /usr/X11R6/inxlude
SRCS = src/draw/draw.c src/error/error.c src/event/events_utils.c src/event/events.c src/event/player_move.c\
		src/map/check_goal.c src/map/check_map_data.c src/map/get_map_data.c src/map/map_utils.c src/map/map.c\
		src/main.c src/draw/init_window_image.c src/error/init_error.c src/draw/make_image.c
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIB_PATH = ./mlx
MINILIB = $(MINILIB_PATH)/libmlx_Linux.a

ifeq ($(shell uname),Darwin)
FRMEWORK = -framework OpenGL -framework Appkit
LIBS = -Lmlx -lmlx_Darwin -L/usr/X11R6/lib -lXext -lX11
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) $(FRMEWORK) $(INLCUDE) -o $(NAME)

$(OBJDIR)/%.o: %.c
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