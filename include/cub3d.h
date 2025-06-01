/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:29:35 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/05 13:29:37 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "constants.h"

# define TITLE "cub3d"
# define PI 3.14159265
# define TWO_PI 6.28318530
# define PI_2 1.5707963267948966
# define MOVE_SPEED 2.0
# define ROTATE_SPEED 0.05
# define FOV_ANGLE 1.0471975512

typedef struct s_graphic
{
	mlx_t		*window;
	mlx_image_t	*img;
}	t_graphic;

typedef struct s_map
{
	int	**wall;
	int	col;
	int	row;
	int	width;
	int	height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	int		move_direction;
	int		strafe_direction;
	int		turn_direction;
	double	rotation_angle;
	double	move_speed;
	double	turn_speed;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	x;
	double	y;
	double	distance;
	bool	found_wall_hit;
}	t_ray;

typedef struct s_game
{
	t_graphic	graphic;
	t_map		map;
	t_player	player;
	t_ray		*rays;
	double		dist_proj_plane;
	double		delta_time;
}	t_game;

void	setup_map(t_game *game);
void	setup_player(t_game *game);
void	setup_graphic(t_game *game);
void	setup_ray(t_game *game);
void	setup_draw(t_game *game);
void	setup_hook(t_game *game);

void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_ray(t_game *game);

void	update(void *param);
void	update_player(t_game *game);
void	cast_rays(t_game *game);

bool	map_has_wall_at(double x, double y);
bool	map_is_inside(double x, double y);

t_ray	horizontal_intersection(t_player *player, double ray_angle);
t_ray	vertical_intersection(t_player *player, double ray_angle);
bool	ray_facing_down(double angle);
bool	ray_facing_up(double angle);
bool	ray_facing_right(double angle);
bool	ray_facing_left(double angle);

void	rect(int x, int y, int w, int h);
void	line(int x1, int y1, int x2, int y2);
void	circle(int x, int y, int r);
void	color(int32_t color);
void	border(int32_t color);

void	normalize_angle(double *angle);
double	distance_between_points(double x1, double y1, double x2, double y2);

void	ft_error(t_game *game);

void	terminate(t_game *game);

#endif
