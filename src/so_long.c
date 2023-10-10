/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:47:12 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/10 18:28:54 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = get_map(check_param(argc, argv));
	data.mlx_p = mlx_init();
	set_struct(&data);
	data.win_p = mlx_new_window(data.mlx_p, data.size.y * 64, data.size.x * 64, "so_long");
	if (!check_map(&data))
		free_struct(&data);
	free_map(data.map);
	data.map = get_map(check_param(argc, argv));
	get_collect_nb(&data);
	ft_printf("co = %d\n", data.collect_nb);
	game_init(data);
	return (1);
}

int	exit_game(t_data *data)
{
	
	free_struct(data);
	exit(0);
}