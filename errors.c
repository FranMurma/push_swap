/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:32 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/12 18:03:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* CHECK de errores. El primero, FT_ERROR, comprueba que al menos hay un segundo argc */
int	ft_error(int argc)
{
	if (argc < 2)
	{
		write (1, "ERROR1: no se ha introducido un numero\n", 39);
		return (-1);
	}
	return (0);
}

/* Segunda comprobacion de errores. FT_ERROR_NB comprueba que los argumentos
 * introducidos son numeros o un - (solo en la primera posicion) */
int	ft_error_nb(char **argv)
{
	int	c1;
	int	c2;

	c1 = 1;
	c2 = 0;
	while (argv[c1])
	{
		c2 = 0;
		while (argv[c1][c2])
		{
			if (((argv[c1][0] == '-' || argv[c1][0] == '+')
					&& (argv[c1][c2 + 1] >= '0' && argv[c1][c2 + 1] <= '9'))
					|| (argv[c1][c2] >= '0' && argv[c1][c2] <= '9'))
				c2++;
			else if (c2 != 0 && argv[c1][c2] >= '0' && argv[c1][c2] <= '9')
				c2++;
			else
			{
				write(1, "ERROR2: un argumento no es un numero\n", 37);
				return (-1);
			}
		}
		c1++;
	}
	return (0);
}

/* Tercera funcion check. FT_NB_REPEATED comprueba que en los argumentos
 * introducidos no hay ningun numero repetido */
int	ft_nb_repeated(char **argv)
{
	int	c1;
	int	c2;

	c1 = 1;
	c2 = 1;
	while (argv[c1])
	{
		c2 = c1 + 1;
		while (argv[c2])
		{
			if (ft_strcmp(argv[c1], argv[c2]) == 0)
			{
				write(1, "ERROR: numero repetido\n", 23);
				return (-1);
			}
			else
				c2++;
		}
		c1++;
	}
	return (0);
}

/* Cuarto check. FT_MAX_MIN comprueba que en los datos introducidos
 * no se supera el valor maximo o minimo de un int */
int	ft_max_min(char **argv)
{
	int	count;

	count = 1;
	while (argv[count])
	{
		if ((ft_l_atoi(argv[count]) >= 2147483647)
			|| (ft_l_atoi(argv[count]) <= -2147483648))
		{
			write (1, "ERROR4: el numero se excede de los limites\n", 43);
			return (-1);
		}
		else
			count++;
	}
	return (0);
}

// Quinto. Comprueba que no este todo ya ordenado (return (0);)
int	ft_sorted (int argc, t_stack *stack_a)
{
	t_element	*tmp1;
	int			count1;

	count1 = 0;
	tmp1 = stack_a->first;

	while (tmp1 && tmp1->next)
	{
		if (tmp1->value < tmp1->next->value)
		{
			count1++;
		}
		tmp1 = tmp1->next;
	}
//	printf("\nLa cantidad de numeros ordenados es: %d", count1 + 1);
	if (count1 == argc -2)
	{
		write (1, "\nERROR5. Numeros ya ordenados\n", 30);
		return (1);
	}
	else
	{
//		write (1, "\nBien, numeros desordenados\n", 30);
		return (0);
	}
}
/*
int	main(int argc, char **argv)
{
	t_list	list; 
	if (ft_error(argc) == -1 || ft_error_nb(argv) == -1
		|| ft_nb_repeated(argv) == -1 || ft_max_min(argv) == -1)
		return (-1);
	printf("TODO ESTA BIEN!\n");
	// ft_setup_stack_a(&list);
	// while (list.stack_a->next)
	// {
	// 	printf("Hola");
	// 	printf("Los argumentos son: %d\n", list.stack_a->data);
	// 	printf("Hola2");
	// 	list.stack_a = list.stack_a->next;
	// }
	return (0);
}
*/
