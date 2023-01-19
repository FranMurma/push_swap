/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:57:16 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/10 18:41:01 by frmurcia         ###   ########.fr       */
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
/*Segundo. stack b no esta vacio pero si el stack a.
 * Subcaso 1: A = 0 y B = 1*/
	else if (stack_a->lenght == 0 && stack_b->lenght == 1)
	{
		stack_a->first = stack_b->first;
		stack_b->first = NULL;
	}
	else if (stack_a->lenght == 0 && stack_b->lenght > 1)
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first->next;
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_a->first->next = NULL;
		stack_a->first->prev = NULL;
		stack_b->first->prev = NULL;
	}
/*El tercero, tanto stack a como stack b no estan vacios */
	else if (stack_a->lenght > 0 &&  stack_b->lenght > 0)
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first->next;
		tmp->next = stack_a->first;
		tmp->prev = NULL;
		stack_a->first->prev = tmp;
		stack_a->first = tmp;
		if (stack_b->lenght > 1)
			tmp2->prev = NULL;
		stack_b->first = tmp2;
	}
	stack_b->lenght = stack_b->lenght - 1;
	stack_a->lenght = stack_a->lenght + 1;
//	printf("El lenght de A es: %d\n", stack_a->lenght);
//	printf("El lenght de B es: %d\n", stack_b->lenght);
	write (1, "pa\n", 3);
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
/* A no esta vacio pero B esta vacio. Subcaso 1, A solo tiene un elemento */
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
		stack_b->first->prev = NULL;
		stack_a->first->prev = NULL;
	}
/*Tercero, ni stack b ni stack a estan vacios*/
	else if (stack_a->lenght > 0 && stack_b->lenght > 0)
	{
		tmp2 = stack_a->first->next;
		tmp = stack_a->first;
		tmp->next = stack_b->first;
		stack_b->first->prev = tmp;
		tmp->prev = NULL;
		stack_b->first = tmp;
		if (stack_a->lenght > 1)
			tmp2->prev = NULL;
		stack_a->first = tmp2;
	}
	stack_b->lenght = stack_b->lenght + 1;
	stack_a->lenght = stack_a->lenght - 1;
	write (1, "pb\n", 3);
//	printf("El lenght de A es: %d\n", stack_a->lenght);
//	printf("El lenght de B es: %d\n", stack_b->lenght);
//	ft_print_stacks(stack_a, stack_b);
}
