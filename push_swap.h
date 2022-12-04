/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/04 19:04:42 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// definimos las estructuras
typedef struct s_element
{
	int					value;
	struct s_element	*next;
	int					index;
}	t_element;

typedef struct s_stack
{
	int			lenght;
	t_element	*first;
}	t_stack;

/* checks */
int			ft_error(int argc);
int			ft_error_nb(char **argv);
int			ft_nb_repeated(char **argv);
int			ft_max_min(char **argv);

/* aux */
int			ft_start(char *str);
int			ft_strcmp(char *s1, char *s2);
long int	ft_l_atoi(char *str);
int			ft_atoi(char *str);

/* crear stacks */
t_stack	ft_create_stack_a(int argc, char **argv);
t_stack ft_create_stack_b();

/* poner indices en los elementos del stack_a*/
void	ft_index(t_stack *stack_a);
#endif
