/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/28 16:02:08 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_items
{
	int				data;
	struct s_items	*next;
	struct s_items	*prev;
	int				index;
}	t_items;

typedef struct s_list
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max_a;
	int		min_a;
	int		len_a;
	int		len_b;
}	t_list;

/* checks*/
int			ft_error(int argc);
int			ft_error_nb(char **argv);
int			ft_nb_repeated(char **argv);
int			ft_max_min(char **argv);

/* aux*/
int			ft_start(char *str);
int			ft_strcmp(char *s1, char *s2);
long int	ft_l_atoi(char *str);
int			ft_atoi(char *str);

#endif
