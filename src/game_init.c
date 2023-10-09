/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:59:52 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/09 14:47:38 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int  deal(int key, t_data data)
{
	ft_printf("%d\n", key);
	if (key == 65307)
		exit(0);
	return (1);
}


/*
	touche w --- 119
	touche a --- 97
	touche s --- 115
	touche d --- 100
	touche ESC --- 65307


*/

/*

int	legal_mov(int key_num, t_data data)
{
	if (key_num == 119 && data.map[data.pos.x -1][data.pos.y] == data.collectible 
			|| data.map[data.pos.x -1][data.pos.y] == data.empty)
	{
		
		move p[x][y] to p[x-1][y]
		replace p[x][y] by empty tile && replace p[x-1][y] by player]
		
	}
	if (key_num == 119)
	if (key_num == 119)
	if (key_num == 119)
}*/




void	fill_wall(t_data data)
{
	data.pos.x = 0;
	data.pos.y = 0;
	while (data.pos.x < data.size.x)
	{
		data.pos.y = 0;
		while (data.pos.y < data.size.y)
		{
			if (data.map[data.pos.x][data.pos.y] == data.wall)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.wall_p, data.pos.y*64, data.pos.x*64);
			if (data.map[data.pos.x][data.pos.y] == data.empty)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.empty_p, data.pos.y*64, data.pos.x*64);
			if (data.map[data.pos.x][data.pos.y] == data.collectible)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.collect_p, data.pos.y*64, data.pos.x*64);
			if (data.map[data.pos.x][data.pos.y] == data.start)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.charac_p, data.pos.y*64, data.pos.x*64);
			if (data.map[data.pos.x][data.pos.y] == data.exit)
				mlx_put_image_to_window(data.mlx_p, data.win_p, data.exit_p, data.pos.y*64, data.pos.x*64);
			data.pos.y++;
		}
		data.pos.x++;
	}
	set_pos(&data);
}


int	game_init(t_data data)
{
	data.win_p = mlx_new_window(data.mlx_p, data.size.y*64, data.size.x*64, "so_long");
	fill_wall(data);
	mlx_key_hook(data.win_p, deal, (void *) &data);
	mlx_loop(data.mlx_p);
	return (1);
}