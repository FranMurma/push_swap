/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:50:55 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/20 13:35:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push a - toma el primer elemento del stack_b y lo pone encima del stack_a.
 * No hace nada si b está vacío.*/
void	ft_pa(**t_stack_a, **t_stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *t_stack_b;

	while (temp_b->next)
		temp_b = temp_b->next;
	temp_b = *t_stack_b;



	if (!*lst)
		lst[0] = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
