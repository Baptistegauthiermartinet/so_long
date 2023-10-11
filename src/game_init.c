/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:59:52 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/11 15:29:31 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_window(t_data data);
int		get_status(t_data *data);

int	deal(int key, t_data *data)
{
	if (key == ESC)
		exit_game(data);
	if (key == W || key == S)
		move_u_d(key, data);
	if (key == A || key == D)
		move_r_l(key, data);
	fill_window(*data);
	set_pos(data);
	if (is_player_at_exit(data) && data->collect_nb == 0)
	{
		ft_printf("Game completed.\n");
		exit_game(data);
	}
	return (1);
}

void	put_image(int i, int j, t_data data)
{
	if (data.map[i][j] == data.wall)
		mlx_put_image_to_window(data.mlx_p, data.win_p, data.wall_p,
			j * SIZE, i * SIZE);
	if (data.map[i][j] == data.empty)
		mlx_put_image_to_window(data.mlx_p, data.win_p, data.empty_p,
			j * SIZE, i * SIZE);
	if (data.map[i][j] == data.collectible)
		mlx_put_image_to_window(data.mlx_p, data.win_p, data.collect_p,
			j * SIZE, i * SIZE);
	if (data.map[i][j] == data.player)
		mlx_put_image_to_window(data.mlx_p, data.win_p, data.charac_p,
			j * SIZE, i * SIZE);
	if (data.map[i][j] == data.exit)
		mlx_put_image_to_window(data.mlx_p, data.win_p, data.exit_p,
			j * SIZE, i * SIZE);
}

void	fill_window(t_data data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data.mlx_p, data.win_p);
	while (i < data.size.x)
	{
		j = 0;
		while (j < data.size.y)
		{
			put_image(i, j, data);
			j++;
		}
		i++;
	}
}

int	game_init(t_data data)
{
	fill_window(data);
	mlx_hook(data.win_p, 2, 1L << 0, deal, &data);
	mlx_hook(data.win_p, 17, 0, (void *)exit_game, &data);
	mlx_loop(data.mlx_p);
	return (1);
}
