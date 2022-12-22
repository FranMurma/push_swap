/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:06 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/22 19:55:52 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"
/*
 * int ft_lenght(t_stack *stack_a)
{
	t_element	*tmp1;
	int			count;

	count = 1;
	tmp1 = stack_a->first;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		count++;
	}
	return (count);
}
*/

// Para entre 6 y 20 numeros hacemos solo 1 chunk
int	ft_long_short(t_stack *stack_a)
{
	int	chunk;

	if (stack_a->lenght > 5 && stack_a->lenght <= 22)
	{
		printf("\nLlegamos al chunk");
		chunk = stack_a->lenght;
		return (chunk);
	}
	else if (stack_a->lenght > 22 && stack_a->lenght <= 100)
	{
		chunk = stack_a->lenght / 5;
		return (chunk);
	}
	return (0);
}

//Miramos de cuanto es cada chunk. Miramos cual es el primer elemento menor que el chunk
//bajando por el stack y le ponemos un contador para saber el numero de movimientos
//que implica llevarlo arriba. A ese nodo lo llamamos hold_first. 
//Retornamos el contador para poder comparar la cantidad de movimientos con los 
//de hold_second.
int	ft_hold_first(t_stack *stack_a)
{
	t_element	*tmp;
	int			count_f;
	int			chunk;

	printf("\neste es el Lenght: %d", stack_a->lenght);
	stack_a->hold_first = NULL;
	count_f = 0;
	tmp = stack_a->first;
	chunk = ft_long_short(stack_a);
	printf ("\nCada chunk es de): %d", chunk);
	while (tmp && (tmp->index > chunk))
	{
		tmp = tmp->next;
		count_f++;
	}
	if (tmp->index <= chunk)
		stack_a->hold_first = tmp;
	printf("\nEl primer valor que esta entre los 11 primeros es: %d", stack_a->hold_first->value);
	printf("\nMovimientos requeridos hacia delante para que sea primero: %d", count_f);
	return (count_f);
}

// Hacemos lo mismo revisando la lista desde abajo.
// El primero que encontramos que esta en el chunk lo llamamos hold_second.
int	ft_hold_second(t_stack *stack_a)
{
	int			chunk;
	t_element	*tmp;
	int			count_s;

	stack_a->hold_second = NULL;
	count_s = 1;
	tmp = stack_a->first;
	chunk = ft_long_short(stack_a);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	while (tmp->prev && tmp->index > chunk)
	{
		tmp = tmp->prev;
		count_s++;
	}
	if (tmp->index <= chunk)
		stack_a->hold_second = tmp;
	printf("\nEl ultimo valor que esta entre los 11 primeros es: %d", stack_a->hold_second->value);
	printf("\nMovimientos requeridos hacia atras para que sea primero: %d", count_s);
	return (count_s);
}

//Comparamos los dos contadores, el de hold_first y el de hold_second.
//El mayor sera el que movamos.
void	ft_compare_holds(t_stack *stack_a, t_stack *stack_b)
{
	int	count_f;
	int	count_s;
	int	tmp;

//Primer problema, el stack b esta vacio, asi que lo metemos los dos primeros numeros
	while (stack_a->lenght > 1)// || stack_a->lenght != stack_a->lenght + stack_b->lenght)
	{
		count_f = ft_hold_first(stack_a);
		count_s = ft_hold_second(stack_a);
		if (count_f < count_s)
			{
				while (stack_b->lenght <= 1)
				{
					printf("\nMetemos algo en el stack_b\n");
					ft_make_pb(stack_a, stack_b);
					ft_print_stacks(stack_a, stack_b);
					if (stack_b->lenght > 1 && stack_b->first->value > stack_b->first->next->value)
						ft_make_rb(stack_b);
				}
				ft_print_stacks(stack_a, stack_b);
				printf("\nEl hold first es: %d\n", stack_a->hold_first->value);
				printf("\nEl first del stack b es: %d\n", stack_b->first->value);
//Ahora hay que chequear si el hold_first es mayor que todos los elementos de b
				tmp = ft_nb_max(stack_b);
				if (stack_a->hold_first->value > tmp)
				{
					printf("\nEmpieza el movimiento\n");
					ft_make_pb(stack_a, stack_b);
					ft_make_rb(stack_b);
					ft_print_stacks(stack_a, stack_b);
				}
				tmp = ft_nb_min(stack_b);
				if (stack_a->hold_first->value < tmp)
				{
					ft_make_rb(stack_b);
					ft_make_pb(stack_a, stack_b);
				}
			}
		}
}
/*


				while (stack_b->lenght > 1)
					if (tmp->value > tmp->next->value)
					{

					}
				{
					printf("EL VALOR EN EL STACK B QUE MIRO ES %d\n", stack_b->first->value);
					ft_make_rb(stack_b);
					ft_print_stacks(stack_a, stack_b);
					ft_make_pb(stack_a, stack_b);
					ft_print_stacks(stack_a, stack_b);
				}
			}
		else if (count_f > count_s)
		{
			if (stack_a->hold_second->value < stack_b->first->value)
			{
				while (stack_b->first->value > stack_b->first->next->value)

				ft_make_rb(stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
		}
		ft_make_pb(stack_a, stack_b);
		ft_print_stacks(stack_a, stack_b);
		ft_compare_holds(stack_a, stack_b);
	}
	return ;
}
*/
