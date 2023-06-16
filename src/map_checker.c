/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:24 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/16 11:09:07 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../includes/so_long.h"

int	get_map()
{
	int		fd;
	char	*str;
	char	*temp;

	str = NULL;
	temp = NULL;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = join_and_free(str, temp);
		
	}
	return (1);
}