/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:03:49 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/05 15:33:11 by bgauthie         ###   ########.fr       */
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
			if (data->map[i][j] == data->start)
			{
				data->pos.x = i;
				data->pos.y = j;
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
	data->start = 'P';
	set_size(data);
	set_pos(data);
	/*set pointeurs et images*/
	
}

bool	print_error(char *str)
{
	ft_printf("Error\n%s", str);
	return (false);
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
