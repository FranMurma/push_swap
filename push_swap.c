/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:41:59 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/04 19:17:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
//Comprobacion de errrores parametros entrada
	if (ft_error(argc) == -1 || ft_error_nb(argv) == -1
		|| ft_nb_repeated(argv) == -1 || ft_max_min(argv) == -1)
		return (-1);
	printf("SIN ERRORES EN LOS DATOS DE ENTRADA!\n");
	stack_a = ft_create_stack_a(argc, argv);
	ft_index(&stack_a);
	while (stack_a.first)
	{
		printf("Valor %d  ", stack_a.first->value);
		printf("Indice %d\n", stack_a.first->index);
		stack_a.first = stack_a.first->next;
	}
	printf("stack_a creado!\n");
	stack_b = ft_create_stack_b();
	printf("stack_b creado!\n");

}
	/*
	t_list	list;

	list.stack_a = ft_create_stack_a(argc, argv);
	list.stack_b = NULL;
	ft_check_sorted(&list);	// ver si esta ordenado y si no, modificar, envia toda la list
	ft_check-sorted(&list.stack_a);//igual que el anterior, pero envia solo el stack_a
		return (0);
}





void	ft_check_sorted(t_list *list);
void	ft_check_sorted(t_list **stack_a)


	t_list	list;
	t_stack *stack_a;

*/
