/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/10 17:52:06 by bgauthie         ###   ########.fr       */
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
	if (fd < 0)
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

bool	check_map(t_data *data)
{
	if (!check_shape(data))
		return (print_error("Map is not rectangular.\n"));
	if (!check_perimeter(data))
		return (print_error("Map perimeter is not closed.\n"));
	if (!check_chars(data) && data->exit_nb != 1)
		return (print_error("Wrong number of exit.\n"));
	if (!check_chars(data) && data->start_nb != 1)
		return (print_error("Wrong number of players. Only one player is allowed.\n"));
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
