/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:45:08 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/21 15:04:59 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_list;

/* checks*/
int			ft_error(int argc, char **argv);
int			ft_error_nb(int argc, char **argv);
int			ft_nb_repeated(char **argv);
int			ft_max_min(char **argv);

/* aux*/
int			ft_start(char *str);
int			ft_strcmp(const char *s1, const char *s2);
long int	ft_l_atoi(char *str);

#endif
