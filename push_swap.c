/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:41:59 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/08 18:40:31 by frmurcia         ###   ########.fr       */
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
	printf("\nSIN ERRORES EN LOS DATOS DE ENTRADA!\n");
//Creamos el stack_a
	stack_a = ft_create_stack_a(argc, argv);
//Ponemos un indice a cada numero en relacion al orden que deben tener
	ft_index(&stack_a);
	t_element		*tmp;
	tmp = stack_a.first;
	while (tmp)
	{
		printf("Valor %d  ", tmp->value);
		printf("Indice %d\n", tmp->index);
		tmp = tmp->next;
	}
//	printf("stack_a creado!\n");
//Creamos el stack_b
	stack_b = ft_create_stack_b();
//	printf("stack_b creado!\n");
//Comprobamos que el stack_a no esta ordenado
	if (ft_sorted(argc, &stack_a) == 1)
	{
		return (0);
	}
/*	printf(VERDE_T"\nEl primer elemento del stack_a vale: %d", stack_a.first->value);
	printf("\nEl segundo elemento del stack-a vale: %d", stack_a.first->next->value);
	ft_sa(&stack_a);
	printf(RESET_COLOR"\nAplicamos la funcion FT_SA");
	printf(VERDE_T"\nEl primer elemento del stack_a vale: %d", stack_a.first->value);
	printf("\nCompruebo que conserve el indice. Indice del primero: %d", stack_a.first->index);
	printf("\nEl segundo elemento del stack-a vale: %d", stack_a.first->next->value);
	printf("\nCompruebo que conserve el indice. Indice del segundo: %d", stack_a.first->next->index);
*/
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
		printf(AMARILLO_T"\nPasamos OTRA VEZ MAS!! la funcion FT_PB\n");
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
	return (0);
}
/*	printf(RESET_COLOR"\nFT_PB. Ahora el stack_b es: %d", stack_b.first->value);
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
