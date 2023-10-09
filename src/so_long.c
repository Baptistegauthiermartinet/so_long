/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:47:12 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/09 11:33:58 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_data	data;
	
	data.map = get_map(check_param(argc, argv));
	data.mlx_p = mlx_init();
	set_struct(&data);
	if (!check_map(&data))
		free_struct(&data);
	free_map(data.map);
	data.map = get_map(check_param(argc, argv));
	game_init(data);
	return (1);
}

