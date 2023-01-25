/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:30:33 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/20 16:04:15 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_max_ y ft_min buscan el maximo y el minimo respectivamente,
// cada uno en sus cadenas, y nos devuelve la posicion en la que estan.
//
int	ft_max_a(t_stack *stack_a)
{
	t_element	*tmp;
	int			nbr_max;
	int			cont;

	cont = 1;
	tmp = stack_a->first;
	nbr_max = tmp->value;
	while (tmp)
	{
		if (nbr_max < tmp->value)
			nbr_max = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack_a->first;
	while (tmp)
	{
		if (nbr_max == tmp->value)
			return (cont);
		cont++;
		tmp = tmp->next;
	}
	return (cont);
}

int	ft_min_a(t_stack *stack_a)
{
	t_element	*tmp;
	int			nbr_min;
	int			cont;

	cont = 1;
	tmp = stack_a->first;
	nbr_min = tmp->value;
	while (tmp)
	{
		if (nbr_min > tmp->value)
			nbr_min = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack_a->first;
	while (tmp)
	{
		if (nbr_min == tmp->value)
			return (cont);
		cont++;
		tmp = tmp->next;
	}
	return (cont);
}

int	ft_max_b(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_max;
	int			cont;

	cont = 1;
	tmp = stack_b->first;
	nbr_max = tmp->value;
	while (tmp)
	{
		if (nbr_max < tmp->value)
			nbr_max = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack_b->first;
	while (tmp)
	{
		if (nbr_max == tmp->value)
			return (cont);
		cont++;
		tmp = tmp->next;
	}
	return (cont);
}

int	ft_min_b(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_min;
	int			cont;

	cont = 1;
	tmp = stack_b->first;
	nbr_min = tmp->value;
	while (tmp)
	{
		if (nbr_min > tmp->value)
			nbr_min = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack_b->first;
	while (tmp)
	{
		if (nbr_min == tmp->value)
			return (cont);
		cont++;
		tmp = tmp->next;
	}
	return (cont);
}
