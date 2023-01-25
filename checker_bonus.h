/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:37:00 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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

typedef struct s_line
{
	char	*line;
	char	*storage;
}	t_line;

/* checks error */
int			ft_error(int argc);
int			ft_error_nb(char **argv);
int			ft_max_min(char **argv);
int			ft_check_sorted(t_stack *stack_a);
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

//Bonus
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
int			ft_strlen(char *str, int is_line);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_have_line(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*ft_xtraspace(char *fed);
char		*ft_read(int fd, char *fed);
void		ft_read_movs(t_stack *stack_a, t_stack *stack_b);
char		*get_next_line(int fd);
char		*ft_strdup(char *s1);
int			ft_strcmp(char *s1, char *s2);
int			ft_check_line(char *line, t_stack *stack_a, t_stack *stack_b);

#endif
