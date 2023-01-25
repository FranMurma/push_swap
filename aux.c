/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:54:53 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/19 16:34:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* FT_L_ATOI, adaptacion de ft_atoi, con un long, comprueba
 * que los datos introducidos no son mayores que el int maximo o minimo */
int	ft_start(char *str)
{
	int	c1;

	c1 = 0;
	while (str[c1] == ' ' || str[c1] == '\n'
		|| str[c1] == '\t' || str[c1] == '\r'
		|| str[c1] == '\v' || str[c1] == '\f')
	{
		c1++;
	}
	return (c1);
}

long int	ft_l_atoi(char *str)
{
	int			count;
	long int	store;
	int			neg;

	count = 0;
	store = 0;
	neg = 1;
	if (str[count] != '\0')
	{
		count = ft_start(str);
		if (str[count] == '+' || str[count] == '-')
		{
			if (str[count] == '-')
				neg = neg * -1;
			count++;
		}
		while (str[count] >= '0' && str[count] <= '9')
		{
			store = (store * 10) + (str[count] - '0');
			count++;
		}
		store = store * neg;
	}
	return (store);
}

int	ft_atoi(char *str)
{
	int	cont1;
	int	almacen;
	int	neg;

	cont1 = 0;
	almacen = 0;
	neg = 1;
	if (str[cont1] != '\0')
	{
		cont1 = ft_start(str);
		if (str[cont1] == '+' || str[cont1] == '-')
		{
			if (str[cont1] == '-')
				neg = neg * -1;
			cont1++;
		}
		while (str[cont1] >= '0' && str[cont1] <= '9')
		{
			almacen = (almacen * 10) + (str[cont1] - '0');
			cont1++;
		}
		almacen = almacen * neg;
	}
	return (almacen);
}
