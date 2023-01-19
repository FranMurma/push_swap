/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:48:04 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/10 18:41:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//swap a - intercambia los dos primeros elementos encima del stack a. 
//No hace nada si hay uno o menos elementos.
void	ft_sa(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;

	if (stack_a->lenght < 2)
		return ;
	else
	{
		first = stack_a->first;
		second = stack_a->first->next;
		first->prev = second->prev;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		stack_a->first = second;
	}
}

//swap b - Intercambia los dos primeros elementos encima del stack b.
//No hace nada si hay menos de dos elementos.
void	ft_sb(t_stack *stack_b)
{
	t_element	*first;
	t_element	*second;

	if (stack_b->lenght < 2)
		return ;
	else
	{
		first = stack_b->first;
		second = stack_b->first->next;
		first->prev = second->prev;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		stack_b->first = second;
	}
}

void	ft_make_sa(t_stack *stack_a)
{
	write (1, "sa\n", 3);
	ft_sa(stack_a);
}

void	ft_make_sb(t_stack *stack_b)
{
	write (1, "sb\n", 3);
	ft_sb(stack_b);
}

void	ft_make_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->lenght >= 2 && stack_b->lenght >= 2)
	{
		write (1, "ss\n", 3);
		ft_sa(stack_a);
		ft_sb(stack_b);
	}
	else
		return ;
}
