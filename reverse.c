/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:03:55 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/20 16:23:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* * @brief 
 * reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
 * @param stack_a   */
void	ft_rra(t_stack *stack_a)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (stack_a->first == NULL)
		return ;
	else if (stack_a->first->next != NULL)
	{
		tmp = stack_a->first;
		tmp2 = stack_a->first;
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp->next = NULL;
		tmp2->next = stack_a->first;
		stack_a->first->prev = tmp2;
		stack_a->first = tmp2;
		stack_a->first->prev = NULL;
		return ;
	}
}

void	ft_rrb(t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (stack_b->first == NULL)
		return ;
	else if (stack_b->first->next != NULL)
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first;
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp->next = NULL;
		tmp2->next = stack_b->first;
		stack_b->first->prev = tmp;
		stack_b->first = tmp2;
		stack_b->first->prev = NULL;
	}
}

void	ft_make_rra(t_stack *stack_a)
{
	write (1, "rra\n", 4);
	ft_rra(stack_a);
}

void	ft_make_rrb(t_stack *stack_b)
{
	write (1, "rrb\n", 4);
	ft_rrb(stack_b);
}

void	ft_make_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	write (1, "rrr\n", 4);
}
