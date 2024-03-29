/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:57:16 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/20 19:28:13 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Toma el primer elemento del stack b y lo pone encima del stack a.
No hace nada si b está vacío.
Seran tres casos. El primero, si el stack b esta vacio
(anadimos la comprobacion de que stack_b tenga elementos)
Segundo: Stack B no vacio, Stack A vacio
Subcaso 1: A = 0 y B = 1
Tercero: Ni A ni B vacios */

void	ft_pa_sub(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;

	tmp = stack_b->first;
	if (stack_b->lenght > 1)
		stack_b->first = stack_b->first->next;
	else if (stack_b->lenght == 1)
		stack_b->first = NULL;
	tmp->next = stack_a->first;
	tmp->prev = NULL;
	stack_a->first = tmp;
}

void	ft_make_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->lenght == 0)
		return ;
	else if (stack_a->lenght == 0 && stack_b->lenght == 1)
	{
		stack_a->first = stack_b->first;
		stack_b->first = NULL;
	}
	else if (stack_a->lenght == 0 && stack_b->lenght > 1)
	{
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_a->first->next = NULL;
	}
	else if (stack_a->lenght > 0 && stack_b->lenght > 0)
		ft_pa_sub(stack_a, stack_b);
	stack_b->lenght = stack_b->lenght - 1;
	stack_a->lenght = stack_a->lenght + 1;
	write (1, "pa\n", 3);
}

/*Toma el primer elemento  del stack a y lo pone encima del stack b.
No hace nada si a esta vacio.*/
void	ft_pb_sub(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;

	tmp = stack_a->first;
	if (stack_a->lenght > 1)
		stack_a->first = stack_a->first->next;
	else if (stack_a->lenght == 1)
		stack_a->first = NULL;
	tmp->next = stack_b->first;
	tmp->prev = NULL;
	stack_b->first = tmp;
}

void	ft_make_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->lenght == 0)
		return ;
	else if (stack_b->lenght == 0 && stack_a->lenght == 1)
	{
		stack_b->first = stack_a->first;
		stack_a->first = NULL;
	}
	else if (stack_b->lenght == 0 && stack_a->lenght > 1)
	{
		stack_b->first = stack_a->first;
		stack_a->first = stack_a->first->next;
		stack_b->first->next = NULL;
	}
	else if (stack_a->lenght > 0 && stack_b->lenght > 0)
	{
		ft_pb_sub(stack_a, stack_b);
	}
	stack_b->lenght = stack_b->lenght + 1;
	stack_a->lenght = stack_a->lenght - 1;
	write (1, "pb\n", 3);
}
