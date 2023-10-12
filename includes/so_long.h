/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:04:36 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/12 19:07:31 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/src/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SIZE 64

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	char	empty;
	char	wall;
	char	collectible;
	char	exit;
	char	player;
	char	**map;
	t_pos	size;
	t_pos	pos;
	t_pos	exit_point;
	int		exit_nb;
	int		start_nb;
	int		collect_nb;
	int		on_exit;
	int		move_nb;
	void	*mlx_p;
	void	*win_p;
	void	*empty_p;
	void	*wall_p;
	void	*collect_p;
	void	*exit_p;
	void	*charac_p;
	int		width;
	int		height;
}				t_data;

/* free.c */
void	free_struct(t_data *data);
void	destroy_images(t_data *data);
void	free_map(char **map);

/* game_init.c */
int		deal(int key, t_data *data);
void	put_image(int i, int j, t_data data);
void	fill_window(t_data data);
int		game_init(t_data data);

/* map_checker_tools.c*/
bool	allowed_chars(t_data *data);
bool	check_shape(t_data *data);
bool	check_perimeter(t_data *data);
bool	check_line(char *str, t_data *data);
bool	check_chars(t_data *data);

/* map_checker.c */
char	**get_map(int fd);
bool	check_map(t_data *data);
bool	is_solvable(t_data *data);
void	fill(t_data *data, char **map, t_pos pos);

/* move.c */
int		move_u_d(int key, t_data *data);
int		move_r_l(int key, t_data *data);
int		legal_move(int dir_x, int dir_y, t_data *data);
void	move_image_u_d(int dir, t_data *data);
void	move_image_r_l(int dir, t_data *data);

/* param_check.c*/
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
int		check_param(int ac, char **av);

/* set_struc.c */
void	set_pos(t_data *data);
void	set_pos_exit(t_data *data);
void	set_size(t_data *data);
void	set_struct(t_data *data);

/* tools.c */
bool	print_error(char *str);
void	get_collect_nb(t_data *data);
int		nb_of(char *str, char c);
int		is_player_at_exit(t_data *data);

int		exit_game(t_data *data);

#endif