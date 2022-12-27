/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:57:16 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/27 17:55:37 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Toma el primer elemento del stack b y lo pone encima del stack a.
No hace nada si b está vacío.*/
void	ft_make_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;
/*Seran tres casos. El primero, si el stack b esta vacio 
(anadimos la comprobacion de que stack_b tenga elementos)*/
	if (stack_b->lenght == 0)
		return ;
/*Segundo. stack b no esta vacio pero si el stack a.*/
	if (stack_a->lenght == 0)
	{
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_a->first->next = NULL;
		stack_b->lenght = stack_b->lenght - 1;
		stack_a->lenght = stack_a->lenght + 1;
		write (1, "pa\n", 3);
	}
/*El tercero, tanto stack a como estack b no estan vacios */
	else if (stack_a->lenght > 0)
	{
		tmp2 = stack_b->first->next;
		tmp = stack_b->first;
		tmp->next = stack_a->first;
		stack_a->first = tmp;
		stack_b->first = tmp2;
		stack_b->lenght = stack_b->lenght - 1;
		stack_a->lenght = stack_a->lenght + 1;
		write (1, "pa\n", 3);
	}
}

/*Toma el primer elemento  del stack a y lo pone encima del stack b.
No hace nada si a esta vacio.*/
void	ft_make_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;
/*Seran tres casos. El primero, si el stack a esta vacio. No hace nada */
	if (stack_a->lenght == 0)
		return ;
/*Segundo caso. Stack a no esta vacio pero stack b si esta vacio */
	if (stack_b->lenght == 0)
	{
		stack_b->first = stack_a->first;
		stack_a->first = stack_a->first->next;
		stack_b->first->next = NULL;
		stack_b->lenght = stack_b->lenght + 1;
		stack_a->lenght = stack_a->lenght - 1;
		write (1, "pb\n", 3);
	}
/*Tercero, ni stack b ni stack a estan vacios*/
	else if (stack_b->lenght >- 0)
	{
		tmp = stack_a->first;
		tmp2 = stack_a->first->next;
		tmp->next = stack_b->first;
		stack_b->first = tmp;
		stack_a->first = tmp2;
		stack_b->lenght = stack_b->lenght + 1;
		stack_a->lenght = stack_a->lenght - 1;
		write (1, "pb\n", 3);
	}
}
