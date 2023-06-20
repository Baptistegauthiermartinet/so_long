/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/20 16:58:23 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map()
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

