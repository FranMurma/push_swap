/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:53 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/26 19:23:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_stack	*ft_setup_stack_a(int argc, char **argv)
{
	int	start;
	start = 2;
	t_list	*stack_a;
	t_stack	*temp;
	t_stack	*node;
	t_list	*list;

	printf("Hola que tal\n");
	stack_a = (t_list *)malloc(sizeof(t_list));
	if (!stack_a)
		return (NULL);
	printf("Hola que tal\n");
	list->stack_a->data = 0;
	list->stack_a->next = NULL;
	printf("Hola que tal\n");
	while (start < argc)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (!node)
			return (NULL);
		node->data = ft_l_atoi(argv[start]);
		node->next = node;
		start++;
	}
	node->next = NULL;
	return (0);
}
