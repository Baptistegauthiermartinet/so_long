/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:59:52 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/10 17:18:10 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_window(t_data data);

int	deal(int key, t_data *data)
{
//	ft_printf("%d\n", key);
	if (key == ESC)
		exit_game(data);
	if (key == W || key == S)
		move_u_d(key, data);
	if (key == A || key == D)
		move_r_l(key, data);
	fill_window(*data);
	set_pos(data);
	return (1);
}

void	fill_window(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.size.x)
	{
		j = 0;
		while (j < data.size.y)
		{
			if (data.map[i][j] == data.wall)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.wall_p, j * 64, i * 64);
			if (data.map[i][j] == data.empty)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.empty_p, j * 64, i * 64);
			if (data.map[i][j] == data.collectible)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.collect_p, j * 64, i * 64);
			if (data.map[i][j] == data.player)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.charac_p, j * 64, i * 64);
			if (data.map[i][j] == data.exit)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.exit_p, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	game_init(t_data data)
{
	fill_window(data);
	mlx_key_hook(data.win_p, deal, (void *) &data);
	mlx_loop(data.mlx_p);
	return (1);
}
