/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:09:47 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/10 17:27:41 by bgauthie         ###   ########.fr       */
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

void	free_ptrs(t_data *data)
{
	if (data->mlx_p)
		free(data->mlx_p);
	if (data->win_p)
		free(data->win_p);
	if (data->empty_p)
		free(data->empty_p);
	if (data->wall_p)
		free(data->wall_p);
	if (data->collect_p)
		free(data->collect_p);
	if (data->exit_p)
		free(data->exit_p);
	if (data->charac_p)
		free(data->charac_p);
}

void	free_struct(t_data *data)
{
	free_map(data->map);
	free_ptrs(data);
}
