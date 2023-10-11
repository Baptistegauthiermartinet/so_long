/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:31:05 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/11 15:35:16 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_shape(t_data *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
			return (false);
		i++;
	}
	return (true);
}

bool	check_perimeter(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(data->map[i]);
	if (!check_line(data->map[i], data))
		return (false);
	i++;
	while (data->map[i])
	{
		if (data->map[i][0] != data->wall
			|| data->map[i][len - 1] != data->wall)
			return (false);
		i++;
	}
	if (!check_line(data->map[i - 1], data))
		return (false);
	return (true);
}

bool	check_line(char *str, t_data *data)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != data->wall)
			return (false);
		i++;
	}
	return (true);
}

bool	check_chars(t_data *data)
{
	size_t	i;

	i = 0;
	data->exit_nb = 0;
	data->start_nb = 0;
	data->collect_nb = 0;
	while (data->map[i])
	{
		data->exit_nb += nb_of(data->map[i], data->exit);
		data->start_nb += nb_of(data->map[i], data->player);
		data->collect_nb += nb_of(data->map[i], data->collectible);
		i++;
	}
	if (data->exit_nb == 1 && data->start_nb == 1 && data->collect_nb >= 1)
		return (true);
	return (false);
}
