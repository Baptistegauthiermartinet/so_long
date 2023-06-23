/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/23 16:16:12 by bgauthie         ###   ########.fr       */
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
	int		exit;
	int		start;
	int		collect;

	i = 0;
	exit = 0;
	start = 0;
	collect = 0;
	while (data->map[i])
	{
		exit += nb_of(data->map[i], data->exit);
		start += nb_of(data->map[i], data->start);
		collect += nb_of(data->map[i], data->collectible);
		i++;
	}
	if (exit == 1 && start == 1 && collect >= 1)
		return (true);
	return (false);
}

