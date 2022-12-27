/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:32 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/27 18:09:19 by frmurcia         ###   ########.fr       */
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
 * introducidos son numeros, un - o un + (solo en la primera posicion) */
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

/*
* Tercera funcion check. FT_NB_REPEATED comprueba que en los argumentos
 * introducidos no hay ningun numero repetido *
 * LO ELIMINO. Al pasarlo antes de convertirlo en numeros no reconoce que un 0004 sea lo mismo que 4. Sustituido por ft_error_dup
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
*/

int	ft_error_dup(t_stack *stack_a)
{
	t_element	*tmp1;
	t_element	*tmp2;

	tmp1 = stack_a->first;
	while (tmp1)
	{
		tmp2 = tmp1;
		while (tmp2->next && (tmp1->index != tmp2->next->index))
		{
			tmp2 = tmp2->next;
		}
		if (tmp2->next && (tmp1->index == tmp2->next->index))
		{
			write(1, "ERROR3. Numero duplicado\n", 25);
			return (-1);
		}
		else if (!tmp2->next)
			tmp1 = tmp1->next;
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
int	ft_sorted(t_stack *stack_a)
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
	if (count1 == stack_a->lenght -1)
	{
		write (1, "\nERROR5. Numeros ya ordenados\n", 30);
		return (-1);
	}
	else
	{
//		write (1, "\nBien, numeros desordenados\n", 30);
		return (0);
	}
}
