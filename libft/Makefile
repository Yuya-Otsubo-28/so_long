# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 13:28:39 by yotsubo           #+#    #+#              #
#    Updated: 2022/11/19 18:26:37 by yotsubo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
LIBFT_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_split.c\
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
		ft_ltoa.c ft_deci_to_hexa.c ft_putuchar_fd.c ft_utoa.c ft_putnstr_fd.c\
		printf_putstr_fd.c printf_putuchar.c ft_atol.c ft_strcmp.c ft_strndup.c\
		ft_printf.c print_args_utils.c
GNL_PATH = ./gnl
GNL_SRCS = $(GNL_PATH)/get_next_line_utils.c $(GNL_PATH)/get_next_line.c
SRCS = $(LIBFT_SRCS) $(GNL_SRCS)
OBJS	= $(SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I include

all	: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(GNL)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

.c.o :
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

re : fclean all

.PHONY : all .c.o clean fclean re
