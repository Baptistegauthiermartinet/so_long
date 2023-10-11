/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/11 15:31:43 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(int fd)
{	
	char	*str;
	char	*temp;
	char	**map;

	str = NULL;
	temp = NULL;
	if (fd <= 0)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = join_and_free(str, temp);
		free(temp);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

bool	check_map(t_data *data)
{
	if (!check_shape(data))
		return (print_error("Map is not rectangular.\n"));
	if (!check_perimeter(data))
		return (print_error("Map perimeter is not closed.\n"));
	if (!check_chars(data) && data->exit_nb != 1)
		return (print_error("Wrong number of exit.\n"));
	if (!check_chars(data) && data->start_nb != 1)
	{
		if (data->start_nb > 1)
			return (print_error("Only one player is allowed.\n"));
		else
			return (print_error("Player is missing.\n"));
	}
	if (!check_chars(data) && data->collect_nb < 1)
		return (print_error("You need at least one collectible on the map.\n"));
	if (!is_solvable(data))
		return (print_error("Map is not solvable.\n"));
	return (true);
}

void	fill(t_data *data, char **map, t_pos pos)
{
	if (pos.x < 0 || pos.x >= data->size.x || pos.y < 0
		|| pos.y >= data->size.y || map[pos.x][pos.y] == data->wall)
		return ;
	if (map[pos.x][pos.y] == data->collectible)
		data->collect_nb--;
	if (map[pos.x][pos.y] == data->exit)
		data->exit_nb--;
	if (map[pos.x][pos.y] == data->player)
		data->start_nb--;
	map[pos.x][pos.y] = '1';
	fill(data, map, (t_pos){pos.x - 1, pos.y});
	fill(data, map, (t_pos){pos.x + 1, pos.y});
	fill(data, map, (t_pos){pos.x, pos.y - 1});
	fill(data, map, (t_pos){pos.x, pos.y + 1});
}

bool	is_solvable(t_data *data)
{
	fill(data, data->map, data->pos);
	if (data->collect_nb == 0 && data->exit_nb == 0 && data->start_nb == 0)
		return (true);
	return (false);
}
