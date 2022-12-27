/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midlong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:56:35 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/27 18:16:43 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_long_short(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a && stack_a->first != NULL)
	{
		ft_make_pb(stack_a, stack_b);
	}
	ft_print_stacks(stack_a, stack_b);
	ft_refill(stack_a, stack_b);
}

/*Igualamos el tmp con el max_b. Con eso tenemos un contador
que nos dira si sale mas a cuenta hacer un RB o un RRB.*/
void	ft_refill(t_stack *stack_a, t_stack *stack_b)
{
	int			max_b;
	int			count;
	t_element	*tmp;

	while (stack_b && stack_b->lenght > 0)
	{
		tmp = stack_b->first;
		count = 0;
		while (tmp->next && tmp->value != max_b)
		{
			tmp = tmp->next;
			count++;
			if (stack_b->lenght - count <= (stack_b->lenght / 2))
			{
				while (stack_b->first != NULL)
				{
					max_b = ft_nb_max(stack_b);
					while (stack_b->first->value != max_b)
					{
						ft_make_rb(stack_b);
					}
					ft_make_pa(stack_a, stack_b);
				}
			}
			else if (stack_b && (stack_b->lenght - count)
				> (stack_b->lenght / 2))
			{
				while (stack_b && stack_b->lenght > 0)
				{
					max_b = ft_nb_max(stack_b);
					while (stack_b && stack_b->first->value != max_b)
					{
						ft_make_rrb(stack_b);
					}
					ft_make_pa(stack_a, stack_b);
				}
			}
		}
		ft_print_stacks(stack_a, stack_b);
	}
}
