/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:58:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/14 19:12:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Si son dos numeros, obviamente solo hay que swapear los dos primeros */
void	ft_two_num(t_stack *stack_a)
{
	ft_make_sa(stack_a);
}

void	ft_three_num(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;
	int	count;
	(void)stack_b;

	count = 0;
//buscamos los maximos y minimos en el stack A	
	max = ft_max_a(stack_a);
    min = ft_min_a(stack_a);
// En el caso de que el minimo sea el primero. Seria un caso 1 3 2,
// de otro modo ya estaria ordenado
	if (min == 1 && max == 2)// 1 3 2
	{
		ft_make_rra(stack_a);
		ft_make_sa(stack_a);
	}
	if (min == 1 && max == 3)
	{
	}
	else if (min == 2 && max == 1)//3 1 2
		ft_make_ra(stack_a);
	else if (min == 2 && max == 3)//2 1 3
		ft_make_sa(stack_a);
	else if (min == 3 && max == 1)//3 2 1
	{
		ft_make_sa(stack_a);
		ft_make_rra(stack_a);
	}
	else if (min == 3 && max == 2)//2 3 1
		ft_make_rra(stack_a);
//	ft_print_stacks(stack_a, stack_b);
}

void	ft_four_num(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;
	int	count;

	count = 0;	
    min = ft_min_a(stack_a);
    max = ft_max_a(stack_a);
	if (min == 2)
	{
		ft_make_sa(stack_a);
	}
	else if (min == 3)
	{
		ft_make_ra(stack_a);
		ft_make_ra(stack_a);
	}
	else if (min == 4)
	{
		ft_make_rra(stack_a);
	}
	ft_make_pb(stack_a, stack_b);
	ft_three_num(stack_a, stack_b);
	ft_make_pa(stack_a, stack_b);
//	ft_print_stacks(stack_a, stack_b);
}

void	ft_five_num(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

    min = ft_min_a(stack_a);
    max = ft_max_a(stack_a);
	
	if (min == 2)
	{
		ft_make_sa(stack_a);
	}
	if (min == 3)
	{
		ft_make_ra(stack_a);
		ft_make_ra(stack_a);
	}
	if (min == 4)
	{
		ft_make_rra(stack_a);
		ft_make_rra(stack_a);
	}
	if (min == 5)
		ft_make_rra(stack_a);
	ft_make_pb(stack_a, stack_b);
	ft_four_num(stack_a, stack_b);
	ft_make_pa(stack_a, stack_b);
//	ft_print_stacks(stack_a, stack_b);
}
