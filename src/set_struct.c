/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:59:22 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/11 15:59:39 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->player)
			{
				data->pos.x = i;
				data->pos.y = j;
			}
			j++;
		}
		i++;
	}
}

void	set_pos_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->exit)
			{
				data->exit_point.x = i;
				data->exit_point.y = j;
			}
			j++;
		}
		i++;
	}
}

void	set_size(t_data *data)
{
	int	line;
	int	raw;

	line = 0;
	raw = 0;
	while (data->map[line][raw])
		raw++;
	while (data->map[line])
		line++;
	data->size.x = line;
	data->size.y = raw;
}

void	set_struct(t_data *data)
{
	data->empty = '0';
	data->wall = '1';
	data->collectible = 'C';
	data->exit = 'E';
	data->player = 'P';
	data->move_nb = 0;
	data->on_exit = 0;
	data->win_p = 0;
	set_size(data);
	set_pos(data);
	data->wall_p = mlx_xpm_file_to_image(data->mlx_p,
			"pictures/wall.xpm", &(data->width), &(data->height));
	data->exit_p = mlx_xpm_file_to_image(data->mlx_p,
			"pictures/exit.xpm", &(data->width), &(data->height));
	data->empty_p = mlx_xpm_file_to_image(data->mlx_p,
			"pictures/empty.xpm", &(data->width), &(data->height));
	data->collect_p = mlx_xpm_file_to_image(data->mlx_p,
			"pictures/collect.xpm", &(data->width), &(data->height));
	data->charac_p = mlx_xpm_file_to_image(data->mlx_p,
			"pictures/player.xpm", &(data->width), &(data->height));
}
