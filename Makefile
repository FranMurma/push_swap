# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:45:09 by frmurcia          #+#    #+#              #
#    Updated: 2022/11/28 16:50:12 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = push_swap.a

CC = gcc
SRC = push_swap.c aux.c add_stack.c moves.c

# SRC_BONUS = 

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
# OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER = push_swap.h

RM = rm -Rf -o .ft_ -o

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	$(FLAGS) $(NAME) $(OBJ)

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

.PHONY = all clean fclean re bonus
