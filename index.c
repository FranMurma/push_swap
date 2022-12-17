/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:58:52 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/17 16:31:52 by frmurcia         ###   ########.fr       */
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
/* Eliminamos de aqui el ft_lenght, lo usaremos en el maxmin.c 
int ft_lenght(t_stack *stack_a)
{
	t_element	*tmp1;
	int			count;

	count = 1;
	tmp1 = stack_a->first;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		count++;
	}
	return (count);
}


 * Elimino la forma de encontrar el min y el max.
 * Aqui min y max estan asociados a indices y nos interesa que
 * no lo esten para poder recalcular el min y el max al cambiar
 * los elementos de cada stack
int ft_max_a(t_stack *stack_a, int count)
{
	t_element	*tmp1;
	int			max;

	count = ft_lenght(stack_a);
	max = 1;
	tmp1 = stack_a->first;
	while (tmp1->next && tmp1->index != count)
	{
		tmp1 = tmp1->next;
		max++;
	}
	return (max);
}

int ft_min_a(t_stack *stack_a)
{
	t_element	*tmp1;
	int			min;

	min = 1;
	tmp1 = stack_a->first;
	while (tmp1->next && tmp1->index != 1)
	{
		tmp1 = tmp1->next;
		min++;
	}
	return (min);
}
*/
