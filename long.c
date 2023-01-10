/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*u                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:06 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/10 17:23:21 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//Miramos de cuanto es cada chunk. Miramos cual es el primer elemento menor que el chunk
//bajando por el stack y le ponemos un contador para saber el numero de movimientos
//que implica llevarlo arriba. A ese nodo lo llamamos hold_first. 
//Retornamos el contador para poder comparar la cantidad de movimientos con los 
//de hold_second. 
int	ft_hold_first(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			count_f;
	int			c_max;
	int			c_min;

	count_f = 0;
	tmp = stack_a->first;
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

	stack_a->hold_second = NULL; //Hace falta?
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
	if (tmp->index >= c_min && tmp->index <= c_max)
	{
		stack_a->hold_second = tmp;
		return (count_s);
	}
	else if ((stack_a->lenght / 2) <= count_s) // OJO, hay que hacer algo distinto con
	{
		stack_a->hold_second = tmp;
		count_s = stack_a->lenght - count_s + 1;
		return (count_s); //Este retorno es diferente del anterior, este debe ir con RRA
	}
	return (0);
}

//Comparamos los dos contadores, el de hold_first y el de hold_second.
//El menor sera el que movamos.
void	ft_long_long(t_stack *stack_a, t_stack *stack_b)
{
	int	min_b;
	int	max_b;
//	int	c_max;
//	int	c_min;

//	c_max = ft_chunk_max(stack_a, stack_b);
//	c_min = ft_chunk_min(stack_a, stack_b);
//Primer problema, el stack b esta vacio, asi que metemos los dos primeros numeros
	if (stack_b->first == NULL)
		ft_firstmovs(stack_a, stack_b);
//Seguimos, despues de meter los dos primeros en el stack B, vamos a por los siguientes:
	min_b = ft_nb_min(stack_b);
	max_b = ft_nb_max(stack_b);
	while (stack_a->lenght)
	{
//Ahora hay que ver si usamos hold_first o hold_second llamando a ft_comp_holdst.
//Si usamos hold_first, lo llevaremos a la primera posicion a base de ra.
//Despues miraremos si es mayor o menor que todo el stack_b.
//Si usamos hold_second, lo llevamos a la primera posicion a base de rra.
//Primer caso, comparamos los holds (first y second) y resulta que retorna 0.
//Eso quiere decir que el movimiento que sale mas a cuenta es RA.
		if (ft_comp_holds(stack_a, stack_b) == 0)
		{
			while ((stack_a && stack_a->hold_first != stack_a->first)
				&& (stack_a && stack_a->hold_second != stack_a->first))
			{
				ft_make_rra(stack_a);
			}
//Si el valor del first (que puede ser hold_first o hold_second) es mayor 
//que todos los elementos del stack b, pondremos el primer elemento de A sobre B. 
//Despues haremos un RB (para que este el ultimo)
			if (stack_a->first->value > max_b)
			{
				ft_make_pb(stack_a, stack_b);
				ft_make_rb(stack_b);
			}
//Si el first es menor que todos los elementos de B, colocamos
//el hold_first sobre el B con un PB.
			else if (stack_a->first->value < min_b)
			{
				ft_make_pb(stack_a, stack_b);
			}
// Si el first no es ni menor que el minimo de B
// ni mayor que el maximo de B, subimos el menor de B arriba del top de B
// con ft_move_b. Luego movemos el hold_first al top de B.
			else if (stack_a->first->value > min_b && stack_a->first->value < max_b)
			{
				ft_move_b(stack_b);
				ft_make_pb(stack_a, stack_b);
			}
		}
//Ahora deberiamos hacer algo similar cuando el retorno de comp_holds es = 1
//(es decir, que sale mas a cuenta hacer RA).
		else if (ft_comp_holds(stack_a, stack_b) == 1)
		{
			while ((stack_a && stack_a->hold_second != stack_a->first)
				|| (stack_a->hold_first != stack_a->first))
			{
				ft_make_ra(stack_a);
			}
			if (stack_a->first->value > max_b)
			{
				ft_make_pb(stack_a, stack_b);
				ft_make_rb(stack_b);
			}
			else if (stack_a->first->value < min_b)
				ft_make_pb(stack_a, stack_b);
			else if (stack_a->first->value > min_b && stack_a->first->value < max_b)
			{
				ft_move_b(stack_b);
				ft_make_pb(stack_a, stack_b);
			}
			printf("Cortamos el while\n");
		}
		ft_print_stacks(stack_a, stack_b);
	}
	ft_make_pb(stack_a, stack_b);
	printf("\nSALIMOS DEL WHILE!!!!!\n");
	ft_print_stacks(stack_a, stack_b);
	ft_refill(stack_a, stack_b);
}
	

void	ft_refill(t_stack *stack_a, t_stack *stack_b)
{
	int			max_b;
	int			count;
	t_element	*tmp;

	while (stack_b->lenght > 0) // (ft_sorted(stack_a) != -1)
	{
		tmp = stack_b->first;
		max_b = ft_nb_max(stack_b);
		count = 0;
//En el proximo while igualamos el tmp con el max_b. Con eso tenemos un contador
//que nos dira si sale mas a cuenta hacer un RB o un RRB.
		while (tmp->next && tmp->value != max_b)
		{
			max_b = ft_nb_max(stack_b);
			tmp = tmp->next;
			count++;
			if (stack_b->lenght - count <= (stack_b->lenght / 2))
			{
				while (stack_b != 0)
				{
					printf("\nEl Max de B es: %d\n", max_b);
					while (stack_b->first->value != max_b)
					{
						ft_make_rb(stack_b);
						printf("\nEl primer valor del stack b ahora es: %d", stack_b->first->value);
					}
					ft_make_pa(stack_a, stack_b);
				}
				return ;
			}
			else if (stack_b->lenght - count > (stack_b->lenght / 2))
			{
				while (stack_b->lenght > 0)
				{
					max_b = ft_nb_max(stack_b);
					while (stack_b->first->value != max_b)
					{
						ft_make_rrb(stack_b);
					}
					ft_make_pa(stack_a, stack_b);
				}
			}
			ft_print_stacks(stack_a, stack_b);
		}
	}
}
