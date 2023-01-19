/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:06 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/18 17:50:04 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//Miramos de cuanto es cada chunk. Miramos cual es el primer elemento menor que el chunk
//bajando por el stack y le ponemos un contador para saber el numero de movimientos
//que implica llevarlo arriba. A ese nodo lo llamamos hold_first. 
//Retornamos el contador para poder comparar la cantidad de movimientos con los 
//de hold_second. Comprobado y funciona OK. 
int	ft_hold_first(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			count_f;
	int			c_max;
	int			c_min;
	int			chunk;
	count_f = 0;
	tmp = stack_a->first;
	chunk = ft_chunk(stack_a, stack_b);
	c_max = ft_chunk_max(stack_a, stack_b);
	c_min = ft_chunk_min(stack_a, stack_b);
//Buscamos la primera aparicion de un numero cuyo valor este en el chunk. Salimos del bucle
//con el tmp en ese numero. El hold_first sera ese numero.
//Rretornamos count_f, que es la posicion de hold_first en el stack.
	while (tmp->next && (tmp->index <= c_min || tmp->index >= c_max))
	{
		tmp = tmp->next;
		count_f++;
	}
	if (tmp->index >= c_min && tmp->index <= c_max)
	{
		stack_a->hold_first = tmp;
		return (count_f); // Este retorno va con RA
	}
	return (0);
}

// Hacemos lo mismo revisando la lista desde abajo.
// El primero que encontramos que esta en el chunk lo llamamos hold_second.
// el retorno es el numero de movimientos necesarios para llevarlo al top del stack.
int	ft_hold_second(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			count_s;
	int			c_max;
	int			c_min;

	count_s = 0;
	tmp = stack_a->first;
	c_max = ft_chunk_max(stack_a, stack_b);
	c_min = ft_chunk_min(stack_a, stack_b);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	while (tmp->prev && (tmp->index > c_max || tmp->index < c_min))
	{
		tmp = tmp->prev;
		count_s++;
	}
	count_s++;
	if (tmp->index >= c_min && tmp->index <= c_max)
	{
		stack_a->hold_second = tmp;
		return (count_s);
	}
	return (0);
}

void	ft_long_long(t_stack *stack_a, t_stack *stack_b)
{
	int			min_chunk;
	int 		max_chunk;

//Primer problema, el stack b esta vacio, asi que metemos los dos primeros numeros
//	if (stack_b->first == NULL)
//		ft_firstmovs(stack_a, stack_b);
//Seguimos, despues de meter los dos primeros en el stack B, vamos a por los siguientes:
	while (stack_a->first)
	{
		max_chunk = ft_chunk_max(stack_a, stack_b);
		min_chunk = ft_chunk_min(stack_a, stack_b);
		while ((stack_a->first->index < min_chunk || stack_a->first->index > max_chunk)
				&& stack_b->lenght <= max_chunk)  // Se puede eliminar la parte del minino?
			{
				ft_make_ra(stack_a);
			}
//		printf("\nEstos son el index del numero que encuentra para enviar a B:  %d.  Y el chunk max en el que ahora estamos %d . Y el chunk min:  %d  \n", stack_a->first->index, max_chunk, min_chunk);
		if (stack_a->first->index > ((max_chunk - min_chunk) / 2) + min_chunk)
			ft_make_pb(stack_a, stack_b);
		else if (stack_a->first->index <= ((max_chunk - min_chunk) / 2) + min_chunk)
		{
			ft_make_pb(stack_a, stack_b);
			ft_make_rb(stack_b);
		}
	}
//	printf("Llegamos al REFILL\n");
//	ft_print_stacks(stack_a, stack_b);
	ft_refill(stack_a, stack_b);
}

/*	ft_make_pb(stack_a, stack_b);
//	ft_three_num(stack_a, stack_b);
	printf("\nSALIMOS DEL WHILE!!!!!\n");
	ft_print_stacks(stack_a, stack_b);
	ft_refill(stack_a, stack_b);
}*/
	
void	ft_refill(t_stack *stack_a, t_stack *stack_b)
{
	int			max_b;
	int			count;
	int			count2;
	t_element	*tmp;
	t_element	*tmp2;
	int			paso;
	int			salida;

	salida = 0;
	paso = 0;
	tmp = stack_b->first;
	tmp2 = stack_b->first;
	while (tmp->next && tmp2->next && stack_b->lenght > 0)
	{
		count = 0;
		count2 = 0;
		tmp = stack_b->first;
		tmp2 = stack_b->first;
		max_b = ft_nb_max(stack_b);
		while (tmp->next && tmp->index != max_b)
		{
			tmp = tmp->next;
			count++;
		}
		while (tmp2->next && tmp2->index != max_b - 1)
		{
			tmp2 = tmp2->next;
			count2++;
		}
		paso++;
		printf("Esta es la %d vez que hacemos el refill\n", paso);
		printf("El maximo ahora en B es: %d \n", max_b);
		printf("Estos son los datos. El contador del maximo es: %d \n El contador del maximo menos 1 es: %d \n  El elegido sera el menor", count, count2);
		if (count < count2)
		{
			if (stack_b->first && count <= stack_b->lenght / 2)
			{
				while (stack_b->first && stack_b->first->index != max_b)
				{
					ft_make_rb(stack_b);
				}
				printf("Este es el index que vamos a pasar al A:   %d \n", stack_b->first->index);
				ft_make_pa(stack_a, stack_b);
				printf("Este es el index que hemos pasado al A     %d \n", stack_a->first->index);
			}
			else if (stack_b->first && count > stack_b->lenght / 2)
			{
				while (stack_b->first && stack_b->first->index != max_b)
				{
					ft_make_rrb(stack_b);
				}
				printf("Este es el index que vamos a pasar al A:     %d \n", stack_b->first->index);
				ft_make_pa(stack_a, stack_b);
				printf("Este es el index que hemos pasado al A     %d \n", stack_a->first->index);
			}
		}
		else if (count > count2)
		{
			if (stack_b->first && count <= stack_b->lenght / 2)
				{
					while (stack_b->first && stack_b->first->index != max_b - 1)
					{
						ft_make_rb(stack_b);
					}
					printf("Este es el index que vamos a pasar al A:   %d \n", stack_b->first->index);
					ft_make_pa(stack_a, stack_b);
					printf("Este es el index que hemos pasado al A     %d \n", stack_a->first->index);
				}
			else if (stack_b->first && count > stack_b->lenght / 2)
			{
				while (stack_b->first && stack_b->first->index != max_b - 1)
				{
					ft_make_rrb(stack_b);
				}
				printf("Este es el index que vamos a pasar al A:     %d \n", stack_b->first->index);
				ft_make_pa(stack_a, stack_b);
				printf("Este es el index que hemos pasado al A     %d \n", stack_a->first->index);
			}
		}
		salida++;
		printf("Por la salida del while grande paso   %d  Veces\n", salida);
		tmp = stack_b->first;
		tmp2 = stack_a->first;
		count = 0;
		count2 = 0;
		max_b = ft_nb_max(stack_b);
	}
	ft_make_pa(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
}

//		printf("El maximo de b ahora es: %d", max_b);
//		ft_print_stacks(stack_a, stack_b);
//		ft_print_stacks(stack_a, stack_b);
//	ft_make_pa(stack_a, stack_b);
//	ft_print_stacks(stack_a, stack_b);
