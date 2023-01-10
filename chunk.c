/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:30:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/10 17:05:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Para mas de 20 numeros hacemos 11 chunks
int	ft_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	nums_per_chunk;
	int	what_chunk;
	int	nb_chunks;
	int	rest;

	nums_per_chunk = (stack_a->lenght + stack_b->lenght) / 11;
	rest = ((stack_a->lenght + stack_b->lenght) % nums_per_chunk);
	printf("Estos son los numeros por cada chunk: %d\n", nums_per_chunk);
	nb_chunks = ((stack_a->lenght + stack_b->lenght) / nums_per_chunk);
	printf("Aqui el numero de chunks son: %d\n", nb_chunks);
//	if ((stack_a->lenght + stack_b->lenght) % nums_per_chunk > 0)
//		nb_chunks = nb_chunks + 1;
//	printf("Y Aqui el numero de chunks, tiene que tener +1, son: %d\n", nb_chunks);	
	what_chunk = (stack_b->lenght / nums_per_chunk) + 1;
	printf("Este es el numero de chunk en el que estamos: %d\n", what_chunk);
	return (what_chunk);
}

int	ft_chunk_max(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_max;
	int	what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	chunk_max = (((stack_a->lenght + stack_b->lenght) / 11) * what_chunk);
	printf("Este es el chunk max: %d\n", chunk_max);
	return (chunk_max);
}

int	ft_chunk_min(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_min;
	int what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	chunk_min = ft_chunk_max(stack_a, stack_b) + 1 - ((stack_a->lenght + stack_b->lenght) / 11);
	printf("Este es el chunk min: %d\n",chunk_min);
	return (chunk_min);
}

int	ft_check_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			chunk_min;
	int			chunk_max;

	chunk_min = ft_chunk_min(stack_a, stack_b);
	chunk_max = ft_chunk_max(stack_a, stack_b);
	printf("\nEstos son los minimos y maximos del chunk: %d,  %d", chunk_min, chunk_max);
	tmp = stack_a->first;
	while (tmp->next && tmp->value < chunk_min && tmp->value > chunk_max)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	return (1);
}
