/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:36:16 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/22 19:55:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Funciones para encontrar el valor maximo y el valor minimo
//en el stack B y que devuelve ese valor para poder compararlo
//con el del stack a cuando llegue el momento de moverlos
//(las otras funciones que buscaban el maximo y el minimo
//nos devolvian solo la posicion de estos valores).
int	ft_nb_max(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_max;

	tmp = stack_b->first;
	nbr_max = tmp->value;
	while (tmp)
	{
		if (nbr_max < tmp->value)
			nbr_max = tmp->value;
		tmp = tmp->next;
	}
	return (nbr_max);
}

int	ft_nb_min(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_min;

	tmp = stack_b->first;
	nbr_min = tmp->value;
	while (tmp)
	{
		if (nbr_min > tmp->value)
			nbr_min = tmp->value;
		tmp = tmp->next;
	}
	return (nbr_min);
}
