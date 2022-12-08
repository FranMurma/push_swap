/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:52 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/05 19:45:40 by frmurcia         ###   ########.fr       */
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
