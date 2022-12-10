/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:48:04 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/10 19:52:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//swap a - intercambia los dos primeros elementos encima del stack a. 
//No hace nada si hay uno o menos elementos.
void	ft_sa(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;

	write(1, "\nsa", 3);

	//if(stack_a->lenght < 2)
	//	return ;

	first = stack_a->first;
	second = stack_a->first->next;

	first->next = second->next;
	second->next = first;
	stack_a->first = second;

	//write(1, "\nsa", 3);
}

//swap b - Intercambia los dos primeros elementos encima del stack b.
//No hace nada si hay menos de dos elementos.
void	ft_sb(t_stack *stack_b)
{
	t_element	*tmp;

	if (stack_b->first->next != NULL)
	{
		tmp = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_b->first = tmp;
	}
	write(1, "\nsb", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "\nss", 3);
}
/*	
 *
 *	{
		tmp.value = stack_a->first->next.value;
		tmp.index = stack_a->first->next.index;
		first->next.value = first.value;
		first->next.index = first.index;
		first.value = tmp.value;
		first.index = tmp.index;
	}	*/
