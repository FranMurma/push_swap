/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 20:09:04 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define RESET_COLOR "\x1b[0m"
# define VERDE_T "\x1b[32m"
# define VERDE_F "\x1b[42m"
# define AMARILLO_T "\x1b[33m"
# define AMARILLO_F "\x1b[43m"

// definition of the estructures
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
}	t_stack;

/* checks error */
int			ft_error(int argc);
int			ft_error_nb(char **argv);
int			ft_max_min(char **argv, t_stack *stack_a);
int			ft_sorted(t_stack *stack_a);
int			ft_error_dup(t_stack *stack_a);

/* aux */
int			ft_start(char *str);
long int	ft_l_atoi(char *str);
int			ft_atoi(char *str);

	/* create stacks */
t_stack		ft_create_stack_a(int argc, char **argv);
t_stack		ft_create_stack_b(void);
void		ft_free_stacks(t_stack *stack_a, t_stack *stack_b);

/* put index to the stack_a elements*/
t_stack		ft_index(t_stack *stack_a);

/* Find max and mins in the stacks */
int			ft_max_a(t_stack *stack_a);
int			ft_min_a(t_stack *stack_a);
int			ft_nb_max(t_stack *stack_b);
int			ft_nb_min(t_stack *stack_b);

// Movements
void		ft_make_sa(t_stack *stack_a);
void		ft_make_sb(t_stack *stack_b);
void		ft_make_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_make_pa(t_stack *stack_a, t_stack *stack_b);
void		ft_make_pb(t_stack *stack_a, t_stack *stack_b);
void		ft_pa_stacks_something(t_stack *stack_a, t_stack *stack_b);
void		ft_pb_stacks_something(t_stack *stack_a, t_stack *stack_b);
void		ft_make_ra(t_stack *stack_a);
void		ft_make_rb(t_stack *stack_b);
void		ft_make_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_make_rra(t_stack *stack_a);
void		ft_make_rrb(t_stack *stack_b);
void		ft_make_rrr(t_stack *stack_a, t_stack *stack_b);

//Actions
void		ft_two_num(t_stack *stack_a);
void		ft_three_num(t_stack *stack_a, t_stack *stack_b);
void		ft_four_num(t_stack *stack_a, t_stack *stack_b);
void		ft_five_num(t_stack *stack_a, t_stack *stack_b);
void		ft_long_short(t_stack *stack_a, t_stack *stack_b);
int			ft_chunk(t_stack *stack_a, t_stack *stack_b);
int			ft_chunk_max(t_stack *stack_a, t_stack *stack_b);
int			ft_chunk_min(t_stack *stack_a, t_stack *stack_b);
void		ft_long_long(t_stack *stack_a, t_stack *stack_b);
void		ft_move_b(t_stack *stack_b);
void		ft_refill(t_stack *stack_a, t_stack *stack_b);

//Bonous
size_t		ft_strlen(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*ft_xtraspace(char *fed);
char		*ft_read(int fd, char *fed);
char		*get_next_line(int fd);
char		*ft_strdup(char *s1);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
