/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:36:16 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/20 16:28:24 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	nbr_max = tmp->index;
	while (tmp)
	{
		if (nbr_max < tmp->index)
			nbr_max = tmp->index;
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
	nbr_min = tmp->index;
	while (tmp)
	{
		if (nbr_min > tmp->index)
			nbr_min = tmp->index;
		tmp = tmp->next;
	}
	return (nbr_min);
}

//Funcion para llevar el elemento mas pequeno del stack_b 
//arriba del todo.
//Nos hara falta para el algoritmo, en el momento en que haya que pasar el 
//hold_first o el hold_second al stack b. Si el h_f o el h_s es mayor o menor
//que todos los elementos del stack_b, simplemente lo pasamos sobre el stack_b.
//Pero si no es asi, hay que mover todo el stack b y poner 
//su elemento minimo arriba del todo.
//Miramos tambien si nos sale mas a cuenta hacer rb o rrb
void	ft_move_b(t_stack *stack_b)
{
	int			min_b;
	int			count;
	t_element	*tmp;

	count = 0;
	min_b = ft_nb_min(stack_b);
	tmp = stack_b->first;
	while (stack_b && tmp->next && tmp->index > min_b)
	{
		tmp = tmp->next;
		count++;
	}
	if (stack_b->lenght / 2 < count)
		while (stack_b && tmp != stack_b->first)
			ft_make_rrb(stack_b);
	else if (stack_b->lenght / 2 >= count)
		while (stack_b && tmp != stack_b->first)
			ft_make_rb(stack_b);
}
