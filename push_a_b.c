/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:57:16 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/08 18:40:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Toma el primer elemento del stack b y lo pone encima del stack a.
//No hace nada si b está vacío.
void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
//Seran dos casos. El primero, si el stack b esta vacio 
//(anadimos la comprobacion de que stack_b tenga elementos)
	if (stack_b == NULL)
		return ;
	if (stack_a->first == NULL)
	{
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_a->first->next = NULL;
		write (1, "pa\n", 3);
	}
//El segundo, si ya hay algo en el stack a
	else if(stack_b->first != NULL)
	{
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		write (1, "pa\n", 3);
	}
}

//Toma el primer elemento  del stack a y lo pone encima del stack b.
//No hace nada si a esta vacio.
void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;
//Seran dos casos. El primero, si el stack b esta vacio.
	if (stack_a == NULL)
		return ;
	if (stack_b->first == NULL)
	{
		stack_b->first = stack_a->first;
		stack_a->first = stack_a->first->next;
		stack_b->first->next = NULL;
		write (1, "pb\n", 3);
	}
//El segundo, si ya hay algo en el stack b
	else if(stack_a->first != NULL)
	{
		tmp2 = stack_a->first->next;
		tmp = stack_a->first;		
		tmp->next = stack_b->first;
		stack_b->first = tmp;
		stack_a->first = tmp2;
/*
		stack_b->first = stack_a->first;
		stack_a->first = stack_a->first->next;*/
		write (1, "pb\n", 3);
	}
}
