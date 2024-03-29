/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:49:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 18:55:40 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_check_line(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_make_pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_make_pb(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_make_sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_make_sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_make_ss(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_make_ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_make_rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_make_rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_make_rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_make_rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_make_rrr(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

void	ft_read_movs(t_stack *stack_a, t_stack *stack_b)
{
	int		error;
	char	*line;

	error = 0;
	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
		if (ft_check_line(line, stack_a, stack_b) == -1)
			error++;
		free(line);
		line = get_next_line(0);
		if (!line || !line[0])
			break ;
	}
	if (error > 0)
	{
		write(1, "KO\n", 3);
		ft_free_stacks(stack_a, stack_b);
		exit (-1);
	}
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc <= 1)
		return (-1);
	stack_a = ft_create_stack_a(argc, argv);
	ft_index(&stack_a);
	stack_b = ft_create_stack_b();
	if (ft_error(argc) == -1 || ft_error_nb(argv) == -1 || ft_max_min(argv)
		|| ft_error_dup(&stack_a) == -1 || ft_check_sorted(&stack_a) == 0)
	{
		ft_free_stacks(&stack_a, &stack_b);
		return (0);
	}
	ft_read_movs(&stack_a, &stack_b);
	if (stack_b.lenght != 0)
		write (1, "KO\n", 3);
	else if (stack_b.lenght == 0)
	{
		if (ft_check_sorted(&stack_a) == 0)
			write(1, "OK\n", 3);
		else if (ft_check_sorted(&stack_a) == -1)
			write(1, "KO\n", 3);
	}
	ft_free_stacks(&stack_a, &stack_b);
}
