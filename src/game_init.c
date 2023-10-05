/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:59:52 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/05 17:06:21 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int  deal(int key)
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




void	fill_wall(t_data data, void *mlx_p, void *win_p, void *image_p)
{
	data.pos.x = 0;
	data.pos.y = 0;
	while (data.pos.x < data.size.x)
	{
		data.pos.y = 0;
		while (data.pos.y < data.size.y)
		{
			if (data.map[data.pos.x][data.pos.y] == data.wall)
				mlx_put_image_to_window(mlx_p, win_p, image_p, data.pos.y*32, data.pos.x*32);
			data.pos.y++;
		}
		data.pos.x++;
	}
}


int	game_init(t_data data)
{
	void	*mlx_p;
	void	*win_p;
	void	*image_p;
	int		width;
	int		height;
	void	*param;
	param = NULL;
	
	mlx_p = mlx_init();
	win_p = mlx_new_window(mlx_p, data.size.y*32, data.size.x*32, "so_long");
	image_p = mlx_xpm_file_to_image(mlx_p, "pictures/wall.xpm", &width, &height);
	fill_wall(data, mlx_p, win_p, image_p);
	mlx_key_hook(win_p, deal,param);
	mlx_loop(mlx_p);
	return (1);
}