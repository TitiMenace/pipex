# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 05:15:52 by tschecro          #+#    #+#              #
#    Updated: 2023/08/26 00:10:49 by titilamenace     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	main.c split.c strjoin.c get_cmd_args.c get_cmd.c \
					get_cmd_utils.c

SRC_DIR 		= src

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))


INCLUDES_DIR	= includes

INCLUDES_FILES	= 	includes.h\
					pipex.h\
					struct.h

INCLUDES		= $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_FILES))

OBJ_DIR = .build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC) )

NAME	=	pipex

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)
			@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c $(INCLUDES)
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_DIR)
						@$(CC) -Wall -Wextra -Werror -g3 -O3 -Ofast -c -I $(INCLUDES_DIR) $< -o $@

clean	:
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_BONUS_DIR)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	all

.PHONY	:	all clean fclean re
