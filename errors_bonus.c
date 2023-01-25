/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:16:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 16:09:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* CHECK de errores. El primero, FT_ERROR, 
 * comprueba que al menos hay un segundo argc */
int	ft_error(int argc)
{
	if (argc < 2)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	ft_write_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
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
		if (!argv[c1][0])
			ft_write_error();
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
				ft_write_error();
		}
		c1++;
	}
	return (0);
}

/* Tercera funcion check. FT_ERROR_DUP comprueba que en los argumentos
 *  introducidos no hay ningun numero repetido **/
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
			write(1, "Error\n", 6);
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
			write (1, "Error\n", 6);
			return (-1);
		}
		else
			count++;
	}
	return (0);
}
