/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:49 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/26 17:28:06 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_struct(t_data *data)
{
	data->empty = '0';
	data->wall = '1';
	data->collectible = 'C';
	data->exit = 'E';
	data->start = 'P';
	data->pos.x = 1;
	data->pos.y = 1;
	
}

void	set_size(char **map, t_pos *size)
{
	int	line;
	int	raw;

	line = 0;
	raw = 0;
	while (map[line][raw])
		raw++;
	while (map[line])
		line++;
	size->x = raw;
	size->y = line;
}

int	print_error(void)
{
	ft_printf("Error\n");
	return (0);
}

void	print_map(t_data *data) /*a virer*/
{
	int	i;

	i = 0;
	while (data->map[i])
		ft_printf("%s\n", data->map[i++]);
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