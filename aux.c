/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:54:53 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/16 17:00:11 by frmurcia         ###   ########.fr       */
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

/* FT_STRCMP, adaptacion de ft_strcmp sin el n, sin devolver unsigned,
 * para el check de errores. 
 * Compara dos strings y comprueba que no haya datos repetidos*/
int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] || s2[count])
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (s1[count] - s2[count]);
	}
	return (0);
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

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_element	*tmp;

	tmp = stack_a->first;
	if (stack_a->first == NULL)
		return ;
    printf(VERDE_T "\nEl stack A es:\n");
    while (tmp)
    {
        printf(RESET_COLOR"Valor %d  ", tmp->value);
        printf("Indice %d\n", tmp->index);
        tmp = tmp->next;
    }
	printf("Lenght A = %d\n", stack_a->lenght);
	printf(VERDE_T "\nEl stack B es:\n");
	tmp = stack_b->first;
	if (stack_b->first == NULL)
		return ;
	while (tmp)
	{
		printf(RESET_COLOR"Valor %d  ", tmp->value);
		printf("Indice %d\n", tmp->index);
		tmp = tmp->next;
	}
	printf("Lenght B =  %d\n", stack_b->lenght);
}
