/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:53:45 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/10 20:03:27 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
int	move_u_d(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;
	if (key == W && legal_move(-1, 0, data))
	{
		data->map[i - 1][j] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	if (key == S && legal_move(1, 0, data))
	{
		data->map[i + 1][j] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	return (1);
}
*/


/*

int	move_r_l(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;
	if (key == A && legal_move(0, -1, data))
	{
		data->map[i][j - 1] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	if (key == D && legal_move(0, 1, data))
	{
		data->map[i][j + 1] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	return (1);
}
*/

/*
int	legal_move(int dir_x, int dir_y, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;
	if (data->map[i + dir_x][j + dir_y] == data->wall)
		return (0);
	if (data->map[i + dir_x][j + dir_y] == data->collectible)
	{
		data->collect_nb--;
		ft_printf("There's %d crystals remaining.\n", data->collect_nb);
	}
	

	return (1);
}
*/
int	move_u_d(int key, t_data *data)
{
	
	if (key == W && legal_move(-1, 0, data))
	{
		move_image_u_d(-1, data);
	}
	if (key == S && legal_move(1, 0, data))
		move_image_u_d(1, data);
	return (1);
}


int	move_r_l(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;
	if (key == A && legal_move(0, -1, data))
	{
		data->map[i][j - 1] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	if (key == D && legal_move(0, 1, data))
	{
		data->map[i][j + 1] = data->player;
		data->map[i][j] = data->empty;
		data->move_nb++;
		ft_printf("You moved %d times.\n", data->move_nb);
	}
	return (1);
}


int	legal_move(int dir_x, int dir_y, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;
	if (data->map[i + dir_x][j + dir_y] == data->wall)
		return (0);
	if (data->map[i + dir_x][j + dir_y] == data->collectible)
	{
		data->collect_nb--;
		ft_printf("There's %d crystals remaining.\n", data->collect_nb);
	}
	if (data->map[i + dir_x][j + dir_y] == data->exit)
		data->on_exit++;;

	return (1);
}


void	move_image_u_d(int dir, t_data *data)
{
	int	i;
	int	j;

	i = data->pos.x;
	j = data->pos.y;

	data->map[i + dir][j] = data->player;
	data->map[i][j] = data->empty;
	data->move_nb++;
	ft_printf("You moved %d times.\n", data->move_nb);
	if (data->on_exit == 2)
		data->map[i][j] = data->exit;
}