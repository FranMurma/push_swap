# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:45:09 by frmurcia          #+#    #+#              #
#    Updated: 2022/12/28 19:22:13 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = push_swap

CC = gcc
SRC = push_swap.c aux.c errors.c add_stack.c index.c swap_a_b.c push_a_b.c rotate.c reverse.c maxmin.c five_mv.c long.c midlong.c utils.c chunk.c
# SRC_BONUS = 

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

# bonus : $(OBJ) $(OBJ_BONUS) $(HEADER)
#	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)
#	@touch $@

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

re : fclean all
norm : 
	@norminette
.PHONY = all clean fclean re norm
