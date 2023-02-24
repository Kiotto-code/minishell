# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 18:29:34 by yichan            #+#    #+#              #
#    Updated: 2023/02/24 14:34:45 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC      =   gcc
RM      =   rm -rf
CFLAGS  =   -Wall -Werror -Wextra -g3
CFLAGS  +=  -fsanitize=address
INCLUDES    = ./includes
SRC_PATH    = ./srcs/*
OBJ_PATH    = ./obj
LIBFT_PATH	= ./libft

SRCS	:= $(wildcard srcs/*/*.c)
# SRCS    = $(wildcard ./srcs/*/*.c)
# OBJS    = ${SRCS:./srcs/%.c=${OBJ_PATH}/%.o}
# SRCS	= ${shell find ./src/libft/ -name "*.c"}
# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
# SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*/*,.c*)))
OBJS	:= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					make -C libft
					$(CC) $(CFLAGS) $^ -L$(LIBFT_PATH) -lft -o $@


$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c* ./includes/*.h ./Makefile | $(OBJ_PATH)
					$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@


$(OBJ_PATH)		:
					mkdir -p $(OBJ_PATH)


clean			:
					rm -rf $(OBJ_PATH)


fclean			:	clean
					rm -rf $(NAME)


re				:   fclean all


.PHONY			:	all clean fclean re
