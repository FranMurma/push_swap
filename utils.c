/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:36:16 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/26 13:46:18 by frmurcia         ###   ########.fr       */
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

	if (count_f <= count_s)
		return (0);
	else if (count_f > count_s)
		return (1);
	return (0);
}

//Funcion que hace los primeros movimientos para llevar los dos primeros numeros
//que iran llenando el stack b.
void	ft_firstmovs(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->lenght == 0)
	{
		ft_make_pb(stack_a, stack_b);
		ft_print_stacks(stack_a, stack_b);
	}
	if (stack_b->lenght == 1)
	{
		if (ft_comp_holds(stack_a, stack_b) == 0)
			ft_make_pb(stack_a, stack_b);
		else if (ft_comp_holds(stack_a, stack_b) == 1)
			{
				ft_make_rra(stack_a);
				ft_make_pb(stack_a, stack_b);
			}
		if (stack_b->lenght > 1 && stack_b->first->value > stack_b->first->next->value)
			ft_make_rb(stack_b);
	}
	ft_print_stacks(stack_a, stack_b);
//	return ;
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
	if (stack_b->lenght - count  < count)
		while (stack_b && tmp != stack_b->first)
		{
			ft_make_rrb(stack_b);
		}
	if (stack_b->lenght - count >= count)
		while (stack_b && tmp != stack_b->first)
		{
			ft_make_rb(stack_b);
		}
}
