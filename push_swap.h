/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/09 20:34:31 by frmurcia         ###   ########.fr       */
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
	struct s_element	*prev;
	int					index;
}	t_element;

typedef struct s_stack
{
	int			lenght;
	t_element	*first;
	t_element	*hold_first;
	t_element	*hold_second;
}	t_stack;

/* checks */
int			ft_error(int argc);
int			ft_error_nb(char **argv);
int			ft_max_min(char **argv);
int			ft_sorted(t_stack *stack_a);
int			ft_error_dup(t_stack *stack_a);

/* aux */
int			ft_start(char *str);
int			ft_strcmp(char *s1, char *s2);
long int	ft_l_atoi(char *str);
int			ft_atoi(char *str);
void		ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int			ft_lenght(t_stack *stack_a);

	/* crear stacks */
t_stack	ft_create_stack_a(int argc, char **argv);
t_stack ft_create_stack_b();

/* poner indices en los elementos del stack_a*/
t_stack	ft_index(t_stack *stack_a);

/* Encontrar maximos y minimos en los stacks */
int ft_lenght(t_stack *stack_a);
int	ft_max_a(t_stack *stack_a);
int ft_min_a(t_stack *stack_a);
int ft_max_b(t_stack *stack_b);
int ft_min_b(t_stack *stack_b);
int ft_nb_max(t_stack *stack_b);
int ft_nb_min(t_stack *stack_b);
int	ft_check_stack(t_stack *stack_a, t_stack *stack_b);

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
void	ft_three_num(t_stack *stack_a, t_stack *stack_b);
void	ft_four_num(t_stack *stack_a, t_stack *stack_b);
void	ft_five_num(t_stack *stack_a, t_stack *stack_b);
void	ft_long_short(t_stack *stack_a, t_stack *stack_b);
int		ft_chunk(t_stack *stack_a, t_stack *stack_b);
int		ft_chunk_max(t_stack *stack_a, t_stack *stack_b);
int		ft_chunk_min(t_stack *stack_a, t_stack *stack_b);
int		ft_hold_first(t_stack *stack_a, t_stack *stack_b);
int		ft_hold_second(t_stack *stack_a, t_stack * stack_b);
void	ft_long_long(t_stack *stack_a, t_stack *stack_b);
int		ft_comp_holds(t_stack *stack_a, t_stack *stack_b);
void	ft_firstmovs(t_stack *stack_a, t_stack *stack_b);
void	ft_move_b(t_stack *stack_b);
void	ft_refill(t_stack *stack_a, t_stack *stack_b);

#endif
