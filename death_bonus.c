/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:50:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/06 16:16:19 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_death(int count1, int count2, t_game *game)
{
//	printf("Entramos en la funcion que printa el 2 con la imagen 10\n");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[10].img_ptr, (count2 * SIZE), (count1 * SIZE));
//	printf("0,3 segundos despues se deberia imprimir esto1\n");
	return (0);
}

int	ft_death_2(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[11].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_death_3(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[12].img_ptr, (count2 * SIZE), (count1 * SIZE));
	usleep (300000);
	return (0);
}

int	ft_death_4(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[13].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}
