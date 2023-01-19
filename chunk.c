/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:30:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/15 13:22:36 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Para mas de 20 numeros hacemos X chunks.
//Dividimos todos los numeros que tenemos por X, con eso obtenemos los numeros por chunk
//Despues, dividimos cuantos numeros tenemos en B por la cantidad de numeros por chunk + 1
int	ft_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	nums_chunk;
	int	what_chunk;

	nums_chunk = (stack_a->lenght + stack_b->lenght) / 7;
	what_chunk = ((stack_b->lenght) / nums_chunk) + 1;
	
	return (what_chunk);
}

// En las dos siguientes funciones miramos cual es el numero maximo del chunk en el que estamos
// y el minimo
int	ft_chunk_max(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_max;
	int	what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	chunk_max = (((stack_a->lenght + stack_b->lenght) / 7) * what_chunk);
//	printf("Este es el chunk max: %d\n", chunk_max);
	return (chunk_max);
}

int	ft_chunk_min(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_min;
	int what_chunk;

	what_chunk = ft_chunk(stack_a, stack_b);
	chunk_min = ft_chunk_max(stack_a, stack_b) + 1 - ((stack_a->lenght + stack_b->lenght) / 7);
//	printf("Este es el chunk min: %d\n",chunk_min);
	return (chunk_min);
}

int	ft_check_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;
	int			chunk_min;
	int			chunk_max;

	chunk_min = ft_chunk_min(stack_a, stack_b);
	chunk_max = ft_chunk_max(stack_a, stack_b);
//	printf("\nEstos son los minimos y maximos del chunk: %d,  %d", chunk_min, chunk_max);
	tmp = stack_a->first;
	while (tmp->next && tmp->index < chunk_min && tmp->index > chunk_max)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	return (1);
}
