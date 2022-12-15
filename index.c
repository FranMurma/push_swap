/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:52 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/15 19:42:57 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_stack	ft_index(t_stack *stack_a)
{
	int			count1;
	t_element	*tmp1;
	t_element	*tmp2;

	tmp1 = stack_a->first;
	while (tmp1)
	{
		count1 = 1;
		tmp2 = stack_a->first;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				count1++;
			tmp2 = tmp2->next;
		}
		tmp1->index = count1;
		tmp1 = tmp1->next;
	}
	return (*stack_a);
}

int ft_lenght(t_stack *stack_a)
{
	t_stack		maxval;
	t_element	*tmp1;
	int			count;

	count = 1;
	maxval = ft_index(stack_a);
	tmp1 = maxval.first;
//	tmp1 = stack_a->first;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		count++;
	}
	return (count);
}

int ft_max_a(t_stack *stack_a, int count)
{
	t_stack		maxval;
	t_element	*tmp1;
	int			max;

	maxval = ft_index(stack_a);
	count = ft_lenght(stack_a);
	max = 1;
	tmp1 = maxval.first;
	while (tmp1->next && tmp1->index != count)
	{
		tmp1 = tmp1->next;
		max++;
	}
	return (max);
}

int ft_min_a(t_stack *stack_a)
{
	t_stack		minval;
	t_element	*tmp1;
	int			min;

	minval = ft_index(stack_a);
	min = 1;
	tmp1 = minval.first;
	while (tmp1->next && tmp1->index != 1)
	{
		tmp1 = tmp1->next;
		min++;
	}
	return (min);
}
