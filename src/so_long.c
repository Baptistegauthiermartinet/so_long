/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:47:12 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/11 15:49:51 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = get_map(check_param(argc, argv));
	if (!data.map)
		return (1);
	data.mlx_p = mlx_init();
	set_struct(&data);
	if (!check_map(&data))
	{
		free_struct(&data);
		return (1);
	}
	data.win_p = mlx_new_window(data.mlx_p,
			data.size.y * SIZE, data.size.x * SIZE, "so_long");
	free_map(data.map);
	data.map = get_map(check_param(argc, argv));
	get_collect_nb(&data);
	set_pos_exit(&data);
	game_init(data);
	return (1);
}

int	exit_game(t_data *data)
{
	free_struct(data);
	exit(0);
}
