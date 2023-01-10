/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/05 15:41:59 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			max;
	int			min;

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
		ft_two_num(&stack_a);
	else if (argc == 4)
		ft_three_num(&stack_a, &stack_b);
	else if (argc == 5)
		ft_four_num(&stack_a, &stack_b);
	else if (argc == 6)
		ft_five_num(&stack_a, &stack_b);
	else if (argc == 7)
	{
		ft_make_ra(&stack_a);
		ft_print_stacks(&stack_a, &stack_b);
		printf("Este es el first->next de A ahora: %d\n", stack_a.first->next->value);
		printf("Este es el prev del segundo: %d\n", stack_a.first->next->prev->value);
		return (0);
	}
	else if (argc > 7 && argc < 21 )
		ft_long_short(&stack_a, &stack_b);
	else if (argc > 20)
		ft_long_long(&stack_a, &stack_b);
}
