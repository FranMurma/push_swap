/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:11:27 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/16 16:31:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack_a)
{
/*rotate a - desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.*/
	t_element	*tmp;
	t_element	*tmp2;

	if (stack_a->first->next == NULL)
		return ;
	else if (stack_a->first->next != NULL)
	{
		tmp = stack_a->first;
		tmp2 = stack_a->first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = tmp2;
		stack_a->first = stack_a->first->next;
		tmp->next = tmp2;
		tmp->next->next = NULL;
	}
}

void	ft_rb(t_stack *stack_b)
{
/*rotate b - desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.*/
	t_element	*tmp;
	t_element	*tmp2;
	
	if (stack_b->lenght == 0 || stack_b->lenght == 1)
		return ;
	else if (stack_b->lenght > 1)
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = tmp2;
		stack_b->first = stack_b->first->next;
		tmp->next = tmp2;
		tmp->next->next = NULL;
	}
}

void	ft_make_ra(t_stack *stack_a)
{
	write (1, "\nra\n", 4);
	ft_ra(stack_a);
}

void	ft_make_rb(t_stack *stack_b)
{
	write (1, "\nrb\n", 4);
	ft_rb(stack_b);
}

void	ft_make_rr(t_stack *stack_a, t_stack *stack_b)
{
	write (1, "\nrr\n", 4);
	ft_ra(stack_a);
	ft_rb(stack_b);
}
