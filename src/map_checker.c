/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/26 18:42:19 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map(void)
{
	int		fd;
	char	*str;
	char	*temp;
	char	**map;

	str = NULL;
	temp = NULL;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = join_and_free(str, temp);
	}
	map = ft_split(str, '\n');
	return (map);
}

int	check_shape(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (print_error());
		i++;
	}
	return (1);
}

bool	check_perimeter(char **map, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[i]);
	if (!check_line(map[i], data))
		return (false);
	i++;
	while (map[i])
	{
		if (map[i][0] != data->wall || map[i][len - 1] != data->wall)
			return (false);
		i++;
	}
	if (!check_line(map[i - 1], data))
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
		data->start_nb += nb_of(data->map[i], data->start);
		data->collect_nb += nb_of(data->map[i], data->collectible);
		i++;
	}
	if (data->exit_nb == 1 && data->start_nb == 1 && data->collect_nb >= 1)
		return (true);
	return (false);
}

void	fill(t_data data, char **map, t_pos pos)
{
	if (pos.x < 0 || pos.x >= data.size.x || pos.y < 0 || pos.y >= data.size.y || map[pos.y][pos.x] == data.wall)
		return ;

	print_map(&data);
	if (map[pos.y][pos.x] == data.collectible)
		data.collect_nb--;
	if (map[pos.y][pos.x] == data.exit)
		data.exit_nb--;
	if (map[pos.y][pos.x] == data.start)
		data.start_nb--;

	map[pos.y][pos.x] = '1';
	fill(data, map, (t_pos){pos.x - 1, pos.y});
	fill(data, map, (t_pos){pos.x + 1, pos.y});
	fill(data, map, (t_pos){pos.x, pos.y - 1});
	fill(data, map, (t_pos){pos.x, pos.y + 1});
	
}

bool	is_solvable(t_data data)
{
	fill(data, data.map, data.pos);
	if (data.collect_nb == 0 && data.exit_nb == 0 && data.start_nb == 0)
		return (true);
	return (false);
}
