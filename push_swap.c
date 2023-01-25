/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 17:14:08 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = ft_create_stack_a(argc, argv);
	ft_index(&stack_a);
	stack_b = ft_create_stack_b();
	if (ft_error(argc) == -1 || ft_error_nb(argv) == -1 || ft_max_min(argv)
		|| ft_error_dup(&stack_a) == -1)
	{
		ft_free_stacks(&stack_a, &stack_b);
		return (-1);
	}
	if (argc == 3)
		ft_two_num(&stack_a);
	else if (argc == 4)
		ft_three_num(&stack_a, &stack_b);
	else if (argc == 5)
		ft_four_num(&stack_a, &stack_b);
	else if (argc == 6)
		ft_five_num(&stack_a, &stack_b);
	else if (argc >= 7 && argc <= 50)
		ft_long_short(&stack_a, &stack_b);
	else if (argc > 50)
		ft_long_long(&stack_a, &stack_b);
	ft_free_stacks(&stack_a, &stack_b);
	return(0);
}
