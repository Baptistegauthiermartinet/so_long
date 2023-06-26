/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:47:12 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/26 18:01:47 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_data	data;

	set_struct(&data);
	data.map = get_map();
	print_map(&data);
	if (!check_perimeter(data.map, &data))
		return (ft_printf("Erreur de map"));
	if (!check_chars(&data))
		return (ft_printf("c error"));
	set_size(data.map, &(data.size));
	if (is_solvable(data))
		ft_printf("map ok\n");
	return (1);
	
	
	

	
/*
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	t_pos pos;
	pos.y = 0;
	pos.x = 500;
	while (pos.x != 1000)
	{
		my_mlx_pixel_put(&img, pos.x, pos.y, 0x00FF0000);
		pos.x += 1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	*/

}

