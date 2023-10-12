/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:49 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/12 16:04:20 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	print_error(char *str)
{
	ft_printf("Error\n%s", str);
	return (false);
}

void	get_collect_nb(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size.x)
	{
		j = 0;
		while (j < data->size.y)
		{
			if (data->map[i][j] == data->collectible)
				data->collect_nb++;
			j++;
		}
		i++;
	}
}

int	nb_of(char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

int	is_player_at_exit(t_data *data)
{
	if (data->pos.x == data->exit_point.x && data->pos.y == data->exit_point.y)
		return (1);
	return (0);
}
