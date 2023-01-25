/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:16:07 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/24 18:17:07 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

//swap a - intercambia los dos primeros elementos encima del stack a.
//No hace nada si hay uno o menos elementos.
void	ft_sa(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;

	if (stack_a->lenght < 2)
		return ;
	else
	{
		first = stack_a->first;
		second = stack_a->first->next;
		first->prev = second->prev;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		stack_a->first = second;
	}
}

//swap b - Intercambia los dos primeros elementos encima del stack b.
//No hace nada si hay menos de dos elementos.
void	ft_sb(t_stack *stack_b)
{
	t_element	*first;
	t_element	*second;

	if (stack_b->lenght < 2)
		return ;
	else
	{
		first = stack_b->first;
		second = stack_b->first->next;
		first->prev = second->prev;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		stack_b->first = second;
	}
}

void	ft_make_sa(t_stack *stack_a)
{
	ft_sa(stack_a);
}

void	ft_make_sb(t_stack *stack_b)
{
	ft_sb(stack_b);
}

void	ft_make_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->lenght >= 2 && stack_b->lenght >= 2)
	{
		ft_sa(stack_a);
		ft_sb(stack_b);
	}
	else
		return ;
}
