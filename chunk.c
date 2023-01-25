/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:30:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/23 18:42:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Para mas de 20 numeros hacemos X chunks.
//Dividimos todos los numeros que tenemos por X, 
//con eso obtenemos los numeros por chunk
//Despues, dividimos cuantos numeros tenemos en B 
//por la cantidad de numeros por chunk + 1
int	ft_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	nums_chunk;
	int	what_chunk;

	if (stack_a->lenght + stack_b->lenght > 50
		&& stack_a->lenght + stack_b->lenght < 101)
		nums_chunk = (stack_a->lenght + stack_b->lenght) / 3;
	else
		nums_chunk = (stack_a->lenght + stack_b->lenght) / 7;
	what_chunk = ((stack_b->lenght) / nums_chunk) + 1;
	return (what_chunk);
}

// En las dos siguientes funciones miramos cual es el numero maximo 
// del chunk en el que estamos y el minimo
int	ft_chunk_max(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_max;
	int	what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	if (stack_a->lenght + stack_b->lenght > 50
		&& stack_a->lenght + stack_b->lenght < 101)
		chunk_max = (((stack_a->lenght + stack_b->lenght) / 3) * what_chunk);
	else
		chunk_max = (((stack_a->lenght + stack_b->lenght) / 7) * what_chunk);
	return (chunk_max);
}

int	ft_chunk_min(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_min;
	int	what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	if (stack_a->lenght + stack_b->lenght > 50
		&& stack_a->lenght + stack_b->lenght < 101)
		chunk_min = ft_chunk_max(stack_a, stack_b) + 1
			- ((stack_a->lenght + stack_b->lenght) / 3);
	else
		chunk_min = ft_chunk_max(stack_a, stack_b) + 1
			- ((stack_a->lenght + stack_b->lenght) / 7);
	return (chunk_min);
}
