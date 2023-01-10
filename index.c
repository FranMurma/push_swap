/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:52 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/30 19:12:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/* Creamos un index asociado. Para calcluar el index, comparamos cada nodo
 * con el siguiente. Si el siguiente es mayor simplemente el siguiente toma
 * el valor del siguiente del siguiente. Se le asocia un contador para que vaya
 * sumando +1 cada vez que hay uno menor. Asi, lo que asocia a cada numero es
 * cuantos menores que el hay */
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
