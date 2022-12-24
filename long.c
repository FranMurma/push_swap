/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:54:06 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/24 20:08:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

// Para entre 6 y 20 numeros hacemos solo 1 chunk
int	ft_long_short(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	printf("\nLlegamos a ft_long_short\n");
	a = stack_a->lenght + stack_b->lenght;
	if (a > 5 && a <= 21)
	{
		printf("\nLlegamos al chunk");
		return (a);
	}
	else if (a > 21 && a <= 100)
	{
		a = stack_a->lenght + stack_b->lenght / 5;
		return (a);
	}
	return (0);
}

//Miramos de cuanto es cada chunk. Miramos cual es el primer elemento menor que el chunk
//bajando por el stack y le ponemos un contador para saber el numero de movimientos
//que implica llevarlo arriba. A ese nodo lo llamamos hold_first. 
//Retornamos el contador para poder comparar la cantidad de movimientos con los 
//de hold_second.
int	ft_hold_first(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			count_f;
	int			chunk;

	printf("\neEste es el Lenght: %d\n", stack_a->lenght);
	count_f = 0;
	tmp = stack_a->first;
	chunk = ft_long_short(stack_a, stack_b);
	printf ("\nCada chunk es de): %d\n", chunk);
//Buscamos la primera aparicion de un numero cuyo valor este en el chunk. Salimos del bucle
//con el tmp en ese numero. El hold_first sera ese numero.
//Rretornamos count_f, que es la posicion de hold_first en el stack.
	while (tmp && (tmp->index > chunk))
	{
		tmp = tmp->next;
		count_f++;
	}
	if (tmp->index <= chunk)
		stack_a->hold_first = tmp;
	printf("\nEl primer valor que esta entre los 20 primeros es: %d", stack_a->hold_first->value);
	printf("\nMovimientos requeridos hacia delante para que sea primero: %d", count_f);
	return (count_f);
}

// Hacemos lo mismo revisando la lista desde abajo.
// El primero que encontramos que esta en el chunk lo llamamos hold_second.
// el retorno es el numero de movimientos necesarios para llevarlo al top del stack.
int	ft_hold_second(t_stack *stack_a, t_stack *stack_b)
{
	int			chunk;
	t_element	*tmp;
	int			count_s;

	stack_a->hold_second = NULL;
	count_s = 1;
	tmp = stack_a->first;
	chunk = ft_long_short(stack_a, stack_b);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	while (tmp->prev && tmp->index > chunk)
	{
		tmp = tmp->prev;
		count_s++;
	}
	count_s = count_s + 1; //Hace falta un movimiento extra.
	if (tmp->index <= chunk)
		stack_a->hold_second = tmp;
	printf("\nEl ultimo valor que esta entre los 20 primeros es: %d", stack_a->hold_second->value);
	printf("\nMovimientos requeridos hacia atras para que sea primero: %d", count_s);
	return (count_s);
}

//Comparamos los dos contadores, el de hold_first y el de hold_second.
//El menor sera el que movamos.
void	ft_compare_holds(t_stack *stack_a, t_stack *stack_b)
{
	int	min_b;
	int	max_b;

//Primer problema, el stack b esta vacio, asi que metemos los dos primeros numeros
	while (stack_a->first)
	{
		if (stack_b->lenght == 0)
		{
			ft_firstmovs(stack_a, stack_b);
			ft_print_stacks(stack_a, stack_b);
		}
//Ahora hay que ver si usamos hold_first o hold_second llamando a ft_comp_holdst.
//Si usamos hold_first, lo llevaremos a la primera posicion a base de ra.
//Despues miraremos si es mayor o menor que todo el stack_b.
//Si usamos hold_second, lo llevamos a la primera posicion a base de rra.

//Primer caso, comparamos los holds (first y second) y resulta que retorna 0.
//Por tanto, count_f es menor que count_s
		else if (ft_comp_holds(stack_a, stack_b) == 0)
		{
			min_b = ft_nb_min(stack_b);
			max_b = ft_nb_max(stack_b);
//Hemos seleccionado el hold_first. Por tanto, mientras que no este en el top,
//le damos ra hasta que llegue. En el caso de un solo chunk aqui no hara nada.
			while (stack_a && stack_a->hold_first != stack_a->first)
			{
				ft_make_ra(stack_a);
				ft_print_stacks(stack_a, stack_b);
			}
//Si el valor de hold first es mayor que todos los elementos del stack b,
// pondremos el primer elemento de A sobre B. Despues haremos un RB 
// (para que este el ultimo)
			if (stack_a->hold_first->value > max_b)
			{
				ft_make_pb(stack_a, stack_b);
				ft_make_rb(stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
//Si el hold_first es menor que todos los elementos de B, colocamos
//el hold_first sobre el B con un PB.
			else if (stack_a->hold_first->value < min_b)
			{
				ft_make_pb(stack_a, stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
// Si el hold_first no es ni menor que el minimo de B
// ni mayor que el maximo de B, subimos el menor de B arriba del top de B
// con ft_move_b. Luego movemos el hold_first al top de B.
			else if (stack_a->hold_first->value > min_b && stack_a->hold_first->value < max_b)
			{
				ft_move_b(stack_b);
				ft_make_pb(stack_a, stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
		}
//Ahora deberiamos hacer algo similar con el Hold_second
		else if (ft_comp_holds(stack_a, stack_b) == 1)
		{
			min_b = ft_nb_min(stack_b);
			max_b = ft_nb_max(stack_b);
			while (stack_a && stack_a->hold_second != stack_a->first)
			{
				ft_make_rra(stack_a);
				ft_print_stacks(stack_a, stack_b);
			}
			if (stack_a->hold_second->value > max_b)
			{
				ft_make_pb(stack_a, stack_b);
				ft_make_rb(stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
			else if (stack_a->hold_second->value < min_b)
				ft_make_pb(stack_a, stack_b);
			else if (stack_a->hold_second->value > min_b && stack_a->hold_second->value < max_b)
			{
				ft_move_b(stack_b);
				ft_make_pb(stack_a, stack_b);
				ft_print_stacks(stack_a, stack_b);
			}
		}
	}
	printf("\nSALIMOS DEL WHILE!!!!!\n");
}
