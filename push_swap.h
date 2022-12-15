/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/15 19:32:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
#define	RESET_COLOR	"\x1b[0m"
#define	VERDE_T		"\x1b[32m"
#define	VERDE_F		"\x1b[42m"
#define	AMARILLO_T	"\x1b[33m"
#define	AMARILLO_F	"\x1b[43m"

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
int			ft_max_min(char **argv);
int			ft_sorted(int argc, t_stack *stack_a);
int			ft_error_dup(t_stack *stack_a);

/* aux */
int			ft_start(char *str);
int			ft_strcmp(char *s1, char *s2);
long int	ft_l_atoi(char *str);
int			ft_atoi(char *str);
void		ft_print_stacks(t_stack *stack_a, t_stack *stack_b);

/* crear stacks */
t_stack	ft_create_stack_a(int argc, char **argv);
t_stack ft_create_stack_b();

/* poner indices en los elementos del stack_a*/
t_stack	ft_index(t_stack *stack_a);
/* Encontrar maximos y minimos en los stacks */
int ft_lenght(t_stack *stack_a);
int	ft_max_a(t_stack *stack_a, int count);
int	ft_min_a(t_stack *stack_a);

// Movimientos
void	ft_make_sa(t_stack *stack_a);
void	ft_make_sb(t_stack *stack_b);
void	ft_make_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_make_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_make_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_make_ra(t_stack *stack_a);
void	ft_make_rb(t_stack *stack_b);
void	ft_make_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_make_rra(t_stack *stack_a);
void	ft_make_rrb(t_stack *stack_b);
void	ft_make_rrr(t_stack *stack_a, t_stack *stack_b);

//Acciones
void	ft_two_num(t_stack *stack_a);
void	ft_three_num(t_stack *stack_a);
void	ft_four_num(t_stack *stack_a, t_stack *stack_b);

#endif
