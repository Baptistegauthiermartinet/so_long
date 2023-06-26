/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:04:36 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/26 18:07:05 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/src/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_data 
{
	char	empty;
	char	wall;
	char	collectible;
	char	exit;
	char	start;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	t_pos	size;
	t_pos	pos;
	int		exit_nb;
	int		start_nb;
	int		collect_nb;
}				t_data;

char	**get_map();
int		check_shape(char **map);
bool	check_perimeter(char **map, t_data *data);
bool	check_line(char *str, t_data *data);
bool	check_chars(t_data *data);




void	set_struct(t_data *data);
void	set_size(char **map, t_pos *size);
int		print_error(void);
void	print_map(t_data *data);
int		nb_of(char *str, char c);

bool	is_solvable(t_data data);
void	fill(t_data data, char **map, t_pos pos);

#endif