/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:59:52 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:02 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int  deal(int key)
{
	ft_printf("%d\n", key);
	return (1);
}





void	fill_wall(t_data data, void *mlx_p, void *win_p, void *image_p)
{
	data.pos.x = 0;
	data.pos.y = 0;
	while (data.pos.x < data.size.x)
	{
		while (data.pos.y < data.size.y)
		{
			if (data.map[data.pos.x][data.pos.y] == data.wall)
				mlx_put_image_to_window(mlx_p, win_p, image_p, data.pos.x*50, data.pos.y*50);
			ft_printf("x = %d	y = %d\n", data.pos.x, data.pos.y);
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
	
	mlx_p = mlx_init();
	win_p = mlx_new_window(mlx_p, data.size.x*50, data.size.y*50, "so_long");
	image_p = mlx_xpm_file_to_image(mlx_p, "pictures/wall.xpm", &width, &height);
	fill_wall(data, mlx_p, win_p, image_p);
	mlx_loop(mlx_p);
	return (1);
}