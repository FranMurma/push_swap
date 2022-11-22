/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:32 by frmurcia          #+#    #+#             */
/*   Updated: 2022/11/22 16:01:12 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CHECK de errores. El primero, FT_ERROR, comprueba que hay un segundo argc */
int	ft_error(int argc, char **argv)
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
int	ft_error_nb(int argc, char **argv)
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
			if ((c2 == 0 && argv[c1][c2] == '-')
					&& (argv[c1][c2 + 1] >= '0' && argv[c1][c2 + 1] <= '9')
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

int	main(int argc, char **argv)
{
	if (ft_error(argc, argv) == -1 || ft_error_nb(argc, argv) == -1
		|| ft_nb_repeated(argv) == -1 || ft_max_min(argv) == -1)
		return (-1);
	else
		write (1, "TODO ESTA BIEN!\n", 16);
	ft_setup_stack_a(argc, argv);
	while (stack_a.next)
	{
		printf("Los argumentos son: %d", stack_a.data);
		stack_a.next;
	}
	return (0);
}
