/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:09:47 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/12 18:52:38 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

void	destroy_images(t_data *data)
{
	if (data->empty_p)
		mlx_destroy_image(data->mlx_p, data->empty_p);
	if (data->wall_p)
		mlx_destroy_image(data->mlx_p, data->wall_p);
	if (data->collect_p)
		mlx_destroy_image(data->mlx_p, data->collect_p);
	if (data->exit_p)
		mlx_destroy_image(data->mlx_p, data->exit_p);
	if (data->charac_p)
		mlx_destroy_image(data->mlx_p, data->charac_p);
}

void	free_struct(t_data *data)
{
	free_map(data->map);
	destroy_images(data);
	if (data->win_p)
		mlx_destroy_window(data->mlx_p, data->win_p);
	mlx_destroy_display(data->mlx_p);
	if (data->mlx_p)
		free(data->mlx_p);
}
