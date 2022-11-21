/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:53 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/21 17:56:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*ft_setup_stack_a(int argc, char **argv)
{
	int	start;
	start = 2;
	t_stack	*stack_a;
	t_stack	*temp;
	t_stack	*node;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->data = 0;
	stack_a->next = NULL;
	while (start < argc)
	{
		nodo = (t_stack *)malloc(sizeof(t_stack));
		if (!nodo)
			return (NULL);
		node->data = ft_l_atoi(argv[start]);
		node->next = node;
		start++;
	}
}
