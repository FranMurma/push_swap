/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:36:16 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/10 17:02:12 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//Funciones para encontrar el valor maximo y el valor minimo
//en el stack B y que devuelve ese valor para poder compararlo
//con el del stack a cuando llegue el momento de moverlos
//(las otras funciones que buscaban el maximo y el minimo
//nos devolvian solo la posicion de estos valores).
int	ft_nb_max(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_max;

	if (!stack_b->first)
		return (0);
	tmp = stack_b->first;
	nbr_max = tmp->value;
	while (tmp)
	{
		if (nbr_max < tmp->value)
			nbr_max = tmp->value;
		tmp = tmp->next;
	}
	return (nbr_max);
}

int	ft_nb_min(t_stack *stack_b)
{
	t_element	*tmp;
	int			nbr_min;
	if (!stack_b->first)
		return (0);

	tmp = stack_b->first;
	nbr_min = tmp->value;
	while (tmp)
	{
		if (nbr_min > tmp->value)
			nbr_min = tmp->value;
		tmp = tmp->next;
	}
	return (nbr_min);
}

//Funcion para comparar que numeros que pertenecen al chunk 
//estan mas alto y mas bajo en la pila y cuantos movimientos
//implica llevarlos a la cima de la pila.
int	ft_comp_holds(t_stack *stack_a, t_stack *stack_b)
{
	int	count_f;
	int	count_s;

	count_f = ft_hold_first(stack_a, stack_b);
	count_s = ft_hold_second(stack_a, stack_b);
	printf("Este es el contador F: %d\n", count_f);
	printf("Y este el contador de S: %d\n", count_s);
	printf("Este es el lenght del stack A en este momento: %d\n", stack_a->lenght);
	if (count_f <= count_s && (stack_a->lenght / 2 >= count_f))
		return (0);
	else if (count_f <= count_s && (stack_a->lenght / 2 < count_f))
		return (1);
	else if (count_f > count_s && (stack_a->lenght / 2 < count_s))
		return (1);
	else if (count_f >= count_s && (stack_a->lenght / 2 >= count_s))
		return (0);
	return (-1);
}

//Funcion que hace los primeros movimientos para llevar los dos primeros numeros
//que iran llenando el stack b.
void	ft_firstmovs(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;
	int			c_max;
	int			c_min;
	int			count;
	int			count2;

	tmp = stack_a->first;
	tmp2 = stack_a->first;
	while (tmp->next && stack_b->lenght < 2)
	{
		c_max = ft_chunk_max(stack_a, stack_b);
		c_min = ft_chunk_min(stack_a, stack_b);
		count2 = 0;
		count = 0;
		while (tmp->next && (tmp->index < c_min || tmp->index > c_max))
		{
			tmp = tmp->next;
			count++;
		}
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
		}
		while (tmp2->prev && (tmp2->index < c_min || tmp2->index > c_max))
		{
			printf("el min es %d y el max es %d\n", c_min, c_max);
			printf("el indice de temp2 es %d\n", tmp2->index);
			tmp2 = tmp2->prev;
			count2++;
		}
		if (count <= count2)
		{
			if (count > stack_a->lenght / 2)
			{
				while (tmp != stack_a->first)
				{
					ft_make_ra(stack_a);
				}
			}
			else if (count <= stack_a->lenght / 2)
			{
				while (tmp != stack_a->first)
				{
					ft_make_ra(stack_a);
				}
			}
		}
		else if (count2 < count)
		{
			if (count2 > (stack_a->lenght / 2))
			{
				while (tmp2 != stack_a->first)
				{
					ft_make_ra(stack_a);
				}
			}
			else if (count2 <= (stack_a->lenght / 2))
			{
				while (tmp2 != stack_a->first)
				{
					ft_make_rra(stack_a);
				}
			}
		}
		ft_make_pb(stack_a, stack_b);
		tmp = stack_a->first;
		tmp2 = stack_a->first;
		ft_print_stacks(stack_a, stack_b);
	}
	printf("Llegamos al final de los first moves\n");
}


//Funcion para llevar el elemento mas pequeno del stack_b arriba del todo.
//Nos hara falta para el algoritmo, en el momento en que haya que pasar el 
//hold_first o el hold_second al stack b. Si el h_f o el h_s es mayor o menor
//que todos los elementos del stack_b, simplemente lo pasamos sobre el stack_b.
//Pero si no es asi, hay que mover todo el stack b y poner su elemento minimo arriba del todo.
//Miramos tambien si nos sale mas a cuenta hacer rb o rrb
void	ft_move_b(t_stack *stack_b)
{
	int			min_b;
	int			count;
	t_element	*tmp;

	count = 0;
	min_b = ft_nb_min(stack_b);
	tmp = stack_b->first;
	while (tmp->next && tmp->value != min_b)
	{
		tmp = tmp->next;
		count++;
	}
	if (stack_b->lenght / 2  < count)
		while (stack_b && tmp != stack_b->first)
		{
			ft_make_rrb(stack_b);
		}
	if (stack_b->lenght / 2 >= count)
		while (stack_b && tmp != stack_b->first)
		{
			ft_make_rb(stack_b);
		}
}
