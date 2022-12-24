/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:41:59 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/24 19:54:51 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		max;
	int		min;

	stack_a = ft_create_stack_a(argc, argv);
//Ponemos un indice a cada numero en relacion al orden que deben tener
	ft_index(&stack_a);
//Creamos el stack_b
	stack_b = ft_create_stack_b();
//Comprobamos que los datos de entrada estan bien pasando las funciones de errors.c
	if (ft_error(argc) == -1 || ft_error_nb(argv) == -1 ||ft_max_min(argv)
		|| ft_error_dup(&stack_a) == -1 || ft_sorted(&stack_a) == -1)
		return (-1);
	printf("\nSIN ERRORES EN LOS DATOS DE ENTRADA!\n");
	max = ft_max_a(&stack_a);
	min = ft_min_a(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	printf("\nEl elemento maximo del stack A esta en la posicion: %d\n", max);
	printf("\nEl elemento minimo de A esta en la posicion: %d\n", min);
	if (argc == 3)
	{
		ft_two_num(&stack_a);
		ft_print_stacks(&stack_a, &stack_b);
		ft_print_stacks(&stack_a, &stack_b);
	}
	if (argc == 4)
	{
		ft_three_num(&stack_a, &stack_b);
		ft_print_stacks(&stack_a, &stack_b);
	}
	if (argc == 5)
	{
		ft_four_num(&stack_a, &stack_b);
		ft_print_stacks(&stack_a, &stack_b);
	}
	if (argc == 6)
	{
		ft_five_num(&stack_a, &stack_b);
		ft_print_stacks(&stack_a, &stack_b);
	}
	if (argc > 6 && argc < 22 )
	{
		ft_compare_holds(&stack_a, &stack_b);
	}
}
/*
 * ft_print_stacks(&stack_a, &stack_b);
	ft_make_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_rr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_sb(&stack_a);
	ft_make_sb(&stack_a);
	ft_make_sb(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_sb(&stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_ss(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_sa(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	ft_make_rrr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
*
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
	printf("-----------------------------------------------");
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
	ft_rr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
	ft_rrr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
	ft_sa(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	printf("-----------------------------------------------");
OJO aqui habia un comentador
	ft_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_ra(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	ft_rb(&stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_rra(&stack_a);
	ft_print_stacks(&stack_a, &stack_b);
	ft_rrb(&stack_b);
	ft_print_stacks(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_print_stacks(&stack_a, &stack_b);

OJO, aqui iba un comentador	
	printf(VERDE_T"\nEl primer elemento del stack_a vale: %d", stack_a.first->value);
	printf("\nEl segundo elemento del stack-a vale: %d", stack_a.first->next->value);
	ft_sa(&stack_a);
	printf(RESET_COLOR"\nAplicamos la funcion FT_SA");
	printf(VERDE_T"\nEl primer elemento del stack_a vale: %d", stack_a.first->value);
	printf("\nCompruebo que conserve el indice. Indice del primero: %d", stack_a.first->index);
	printf("\nEl segundo elemento del stack-a vale: %d", stack_a.first->next->value);
	printf("\nCompruebo que conserve el indice. Indice del segundo: %d", stack_a.first->next->index);

	printf(AMARILLO_T"\nPasamos la funcion FT_PB\n");
	ft_pb(&stack_a, &stack_b);
	t_element	*tmp_b;

	tmp_b = stack_b.first;
	printf(VERDE_T "El stack B es:");
	while (tmp_b)
	{
		printf(RESET_COLOR"\nValor %d  ", tmp_b->value);
 		printf("Indice %d\n", tmp_b->index);
		tmp_b = tmp_b->next;
	}
	tmp = stack_a.first;
	printf(VERDE_T "\nEl stack A es:\n");
	while (tmp)
	{
		printf(RESET_COLOR"Valor %d  ", tmp->value);
		printf("Indice %d\n", tmp->index);
		tmp = tmp->next;
	}
	
	printf(AMARILLO_T"\nPasamos OTRA VEZ la funcion FT_PB\n");
	ft_pb(&stack_a, &stack_b);
	printf(VERDE_T "El stack B es:\n");
	tmp_b = stack_b.first;
	while (tmp_b)
	{
		printf(RESET_COLOR"Valor %d  ", tmp_b->value);
 		printf("Indice %d\n", tmp_b->index);
		tmp_b = tmp_b->next;
	}
	printf(VERDE_T "\nEl stack A es:\n");
	tmp = stack_a.first;
	while (tmp)
	{
		printf(RESET_COLOR"Valor %d  ", tmp->value);
		printf("Indice %d\n", tmp->index);
		tmp = tmp->next;
	}
	printf(AMARILLO_T"\nY AHORA FT_PA\n");
	ft_pa(&stack_a, &stack_b);
	printf(VERDE_T "El stack B es:\n");
	tmp_b = stack_b.first;
	while (tmp_b)
	{
		printf(RESET_COLOR"Valor %d  ", tmp_b->value);
 		printf("Indice %d\n", tmp_b->index);
		tmp_b = tmp_b->next;
	}
	printf(VERDE_T "\nEl stack A es:\n");
	tmp = stack_a.first;
	while (tmp)
	{
		printf(RESET_COLOR"Valor %d  ", tmp->value);
		printf("Indice %d\n", tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

	OJO. aqui iba un comentador
	printf(RESET_COLOR"\nFT_PB. Ahora el stack_b es: %d", stack_b.first->value);
	printf("\nPrimero de stack_a ahora es: %d", stack_a.first->value);
	ft_pb(&stack_a, &stack_b);
	printf("\nFT_PB otra vez. \nEl primero de stack_b es: %d", stack_b.first->value);
	printf("\nEl primero de stack_a ahora es: %d", stack_a.first->value);
//Ahora hacemos lo mismo con ft_pa
	ft_pa(&stack_a, &stack_b);
	printf(RESET_COLOR"\nFT_PA. \nAhora el primero de stack_a es: %d", stack_a.first->value);
	printf("\nPrimero de stack_b ahora es: %d", stack_b.first->value);
	return (0);
}

	t_list	list;
    first = stack_a->first;
    second = stack_a->first->next;

    first->next = second->next;
    second->next = first;
    stack_a->first = second;
	list.stack_a = ft_create_stack_a(argc, argv);
	list.stack_b = NULL;
	ft_check_sorted(&list);	// ver si esta ordenado y si no, modificar, envia toda la list
	ft_check-sorted(&list.stack_a);//igual que el anterior, pero envia solo el stack_a
		return (0);    first = stack_a->first;
    second = stack_a->first->next;

    first->next = second->next;
    second->next = first;
    stack_a->first = second;
}





void	ft_check_sorted(t_list *list);
void	ft_check_sorted(t_list **stack_a)


	t_list	list;
	t_stack *stack_a;

*/
