/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:51:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/04 11:35:03 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (s1[i] && s2[j] && s1[i] == s2[j] && n > 0)
	{
		i--;
		j--;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_param(int ac, char **av)
{
	int	fd;
	
	if (ac != 2)
	{
		return (print_error("Wrong number of argument.\n"));
		return (0);
	}
	if (ft_strrncmp(av[1], ".ber", 4))
	{
		return (print_error("File type should be .ber !\n"));
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		return (print_error("File not found !\nUse `maps/mapname.ber\n"));
		return (0);
	}
	return (fd);
}