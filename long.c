/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:50:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 19:00:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_long_long(t_stack *stack_a, t_stack *stack_b)
{
	int	min_chunk;
	int	max_chunk;

	while (stack_a->first)
	{
		max_chunk = ft_chunk_max(stack_a, stack_b);
		min_chunk = ft_chunk_min(stack_a, stack_b);
		while ((stack_a->first->index > max_chunk)
			&& stack_b->lenght <= max_chunk)
		{
			ft_make_ra(stack_a);
		}
		if (stack_a->first->index > ((max_chunk - min_chunk) / 2)
			+ min_chunk)
			ft_make_pb(stack_a, stack_b);
		else if (stack_a->first->index <= ((max_chunk - min_chunk) / 2)
			+ min_chunk)
		{
			ft_make_pb(stack_a, stack_b);
			ft_make_rb(stack_b);
		}
	}
	ft_refill(stack_a, stack_b);
}

t_stack	ft_refill_first_if(t_stack *stack_a, t_stack *stack_b)
{
	int	max_b;

	max_b = ft_nb_max(stack_b);
	while (stack_b->first && stack_b->first->index != max_b)
	{
		if (stack_b->first->index == max_b -1 && stack_b->first->next->index
			!= max_b)
			ft_make_pa(stack_a, stack_b);
		ft_make_rb(stack_b);
	}
	ft_make_pa(stack_a, stack_b);
	if (stack_a->lenght >= 2 && stack_a->first->next->index == max_b - 1)
		ft_make_sa(stack_a);
	return (*stack_a);
}

t_stack	ft_refill_elseif(t_stack *stack_a, t_stack *stack_b)
{
	int	max_b;

	max_b = ft_nb_max(stack_b);
	while (stack_b->first && stack_b->first->index != max_b)
	{
		if (stack_b->first->index == max_b -1
			&& stack_b->first->next->index != max_b)
			ft_make_pa(stack_a, stack_b);
		ft_make_rrb(stack_b);
	}
	ft_make_pa(stack_a, stack_b);
	if (stack_a->lenght >= 2 && stack_a->first->next->index == max_b - 1)
		ft_make_sa(stack_a);
	return (*stack_b);
}

void	ft_refill(t_stack *stack_a, t_stack *stack_b)
{
	int			max_b;
	int			count;
	t_element	*tmp;

	tmp = stack_b->first;
	while (stack_b->lenght > 0 && tmp->next)
	{
		tmp = stack_b->first;
		max_b = ft_nb_max(stack_b);
		while (tmp->next && tmp->index != max_b)
		{
			tmp = tmp->next;
			count++;
		}
		if (stack_b->first && count <= stack_b->lenght / 2)
			ft_refill_first_if(stack_a, stack_b);
		else if (stack_b->first && count > stack_b->lenght / 2)
			ft_refill_elseif(stack_a, stack_b);
		count = 0;
		tmp = stack_b->first;
	}
	ft_make_pa(stack_a, stack_b);
}

void	ft_long_short(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a && stack_a->first != NULL)
	{
		ft_make_pb(stack_a, stack_b);
	}
	ft_refill(stack_a, stack_b);
}
