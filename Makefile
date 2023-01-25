# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:45:09 by frmurcia          #+#    #+#              #
#    Updated: 2023/01/24 18:45:28 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = push_swap
CHKR = checker

CC = gcc
SRC = push_swap.c aux.c errors.c add_stack.c index.c swap_a_b.c push_a_b.c rotate.c reverse.c maxmin.c five_mv.c long.c utils.c chunk.c
SRC_BONUS = add_stack_bonus.c aux_bonus.c checker_bonus.c errors_bonus.c get_next_line_bonus.c index_bonus.c pa_pb_bonus.c ra_rb_bonus.c rotate_bonus.c sa_sb_bonus.c utils_bonus.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER = push_swap.h
HEADER_BONUS = checker_bonus.h

RM = rm -f

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(CHKR) : $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(CHKR)

all : $(NAME)

bonus : $(CHKR)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(CHKR)
	@echo "$(GREEN)$(NAME)$(CHKR) cleaned!$(NC)"

re : fclean all
norm : 
	@norminette
.PHONY = all clean fclean re norm bonus
