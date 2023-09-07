# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 09:42:10 by wmoughar          #+#    #+#              #
#    Updated: 2023/09/07 17:37:22 by wmoughar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_DIR = sources/

SOURCES = $(addprefix $(SRC_DIR), main.c \
									free.c \
									initialize_game.c \
									$(MAP_CHECK) \
									$(READ_FILE) \
									$(RAY_CAST) \
									$(GAME))

MAP_CHECK = $(addprefix check_map/, ft_check_input.c \
									ft_check_map.c \
									ft_check_map_utils.c \
									ft_check_borders.c \
									ft_check_player.c)

READ_FILE = $(addprefix read_file/, ft_get_file_content.c \
									colors.c \
									ft_check_textures.c)

GAME = $(addprefix game/, controls.c)

RAY_CAST = $(addprefix ray_cast/, raycast.c \
								  raycast_utils.c)

CC = gcc

FRAMEWORKS = -framework OpenGL -framework Appkit

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

HEADER = includes/cub.h

RM = rm -rf

all: lib $(NAME)

lib:
	@make -sC libft
	@make -sC mlx

$(NAME): $(OBJECTS) 
	@$(CC) $(CFLAGS) mlx/libmlx.a libft/libft.a $(FRAMEWORKS) $(OBJECTS) -o $(NAME)
	@echo "\n==========Compiled Successfully==========\n"

$(OBJECTS): $(HEADER)

clean:
	@$(RM) $(OBJECTS)
	@make clean -C  libft
	@make clean -C  mlx
	@$(RM) cub3D.dSYM
	
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@echo "\n==========Cleaned Successfully==========\n"

re: fclean all