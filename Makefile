# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:54:06 by lbenedar          #+#    #+#              #
#    Updated: 2021/02/19 18:10:10 by lbenedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAKE = @make

SRCS =	srcs/cub3d.c \
		srcs/error.c \
		srcs/run_game.c \
		srcs/main.c \
		srcs/open_texs.c \
		srcs/make_bmp.c \
		srcs/parser/ft_pars.c \
		srcs/gnl/get_next_line.c \
		srcs/gnl/get_next_line_utils.c \
		srcs/parser/texs_parser.c \
		srcs/parser/colour_parser.c \
		srcs/parser/map_parser.c \
		srcs/parser/is_plr_inside.c \
		srcs/parser/ft_parse_cub.c \
		srcs/parser/is_map_valid.c \
		srcs/parser/flood_fill.c \
		srcs/parser/res_parser.c \
		srcs/parser/setup_spr.c \
		srcs/parser/sort_spr.c \
		srcs/render/render_frame.c \
		srcs/render/render_walls.c \
		srcs/render/render_sprite.c \
		srcs/render/plr_move.c

#TODO: BONUS_SRCS

OBJS =	$(SRCS:.c=.o)

LIB_DIR = libft

LIB_NAME = libft.a

MLX_DIR = minilibx-linux

MLX_NAME = libmlx.a

SRCS_DIR = srcs

CC = gcc

RM = rm -f

INCLUDES = -Iincludes/ -I$(LIB_DIR) -I$(MLX_DIR)

CFLAGS = -Wall -Werror -Wextra

OPTFLAGS = -O2

BMP = cub3D.bmp

NORM_PATHS = srcs/*.c includes/*.h libft/*.c srcs/render/*.c srcs/parser/*.c srcs/gnl/*.c

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIB_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/$(LIB_NAME) $(SRCS_DIR)/$(MLX_NAME) -o cub3D -lXext -lX11 -lm

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIB_DIR) fclean
	
fclean: clean
	$(RM) $(BMP)
	$(RM) $(NAME)
	
re: fclean all

norm:
	norminette $(NORM_PATHS)

bonus: all

%.o:%.c
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ $(INCLUDES)

