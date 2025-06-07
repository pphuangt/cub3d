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
# include "get_next_line.h"
# include "constants.h"
# include <fcntl.h>

# define TITLE "cub3d"
# define PI 3.14159265
# define TWO_PI 6.28318530
# define PI_2 1.5707963267948966
# define MOVE_SPEED 2.0
# define ROTATE_SPEED 0.05
# define FOV_ANGLE 1.0471975512
# define TILE_SIZE 64
# define PLAYER_WALL_GAP 8
# define PLAYER_POINT 3
# define TEXTURE_COUNT 4
# define MINIMAP_SCALE 0.2
# define RADIUS 8

typedef struct s_graphic
{
	mlx_t		*window;
	mlx_image_t	*img;
}	t_graphic;

typedef struct s_map
{
	char			*wall;
	int				col;
	int				row;
	int				width;
	int				height;
	mlx_texture_t	*textures[4];
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
	int		texture_id;
	bool	found_wall_hit;
	bool	was_hit_vertical;
}	t_ray;

typedef struct s_input
{
	char		*map;
	size_t		row_count;
	size_t		col_count;
	int			posx;
	int			posy;
	char		pos_dirctn;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			f_color_int;
	int			c_color_int;
}	t_input;

typedef struct s_game
{
	t_graphic	graphic;
	t_map		map;
	t_player	player;
	t_ray		*rays;
	t_input		input;
	double		dist_proj_plane;
	double		delta_time;
}	t_game;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

void	setup_map(t_game *game);
void	setup_player(t_game *game);
void	setup_graphic(t_game *game);
void	setup_ray(t_game *game);
void	setup_draw(t_game *game);
void	setup_hook(t_game *game);

void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_ray(t_game *game);
void	render_wall(t_game *game);

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
int		ray_texture_id(double angle, bool is_vertical_hit);

void	rect(int x, int y, int w, int h);
void	line(int x1, int y1, int x2, int y2);
void	circle(int x, int y, int r);
void	color(int32_t color);
void	border(int32_t color);

void	normalize_angle(double *angle);
double	distance_between_points(double x1, double y1, double x2, double y2);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

void	parse(char *filename, t_game *game);
void	parse_map_file(char *in_file, t_game *game);
void	check_map_filename(char *filename, t_game *game);
int		parse_texture(char *filename, t_game *game);
int		check_texture_filename(char **splitted_text_path, t_game *game);
int		parse_color_str(char *filename, t_game *game);
void	convert_colors(t_game *game);
void	get_map_info(char *filename, t_game *game);
void	load_and_validate_map(char *filename, t_game *game);
void    check_map(t_game *game);
void	check_udr(t_game *game, int x, int y);
void	check_udl(t_game *game, int x, int y);
void	check_udlr(t_game *game, int x, int y);

void	check_malloc(void *ptr, t_game *game);
void	free_input_memory(t_game *game);
void	free_and_exit(t_game *game, const char *msg);
char	*skip_texture_lines(int fd);

void	ft_error(t_game *game);

void	terminate(t_game *game);

#endif
