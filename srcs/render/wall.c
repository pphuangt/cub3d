/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:47:07 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/03 08:47:09 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				render_ceil_floor(int width, int height);
static void				render_projection_wall(t_game *game, int width);
static void				draw_wall_texture(t_game *game, mlx_texture_t *texture,
							double wall_height, int i);
static int32_t			texture_pixel_color(mlx_texture_t *texture,
							int texture_offset_x, int texture_offset_y);

void	render_wall(t_game *game)
{
	t_map	*map;

	map = &game->map;
	render_ceil_floor(map->width, map->height);
	render_projection_wall(game, map->width);
}

static void	render_ceil_floor(int width, int height)
{
	border(BLUE);
	color(BLUE);
	rect(0, 0, width, height / 2);
	border(GREY);
	color(GREY);
	rect(0, height / 2, width, height / 2);
}

static void	render_projection_wall(t_game *game, int width)
{
	double			wall_height;
	double			correct_distance;
	int				i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < width)
	{
		correct_distance = game->rays[i].distance
			* cos(game->player.rotation_angle - game->rays[i].angle);
		wall_height = (TILE_SIZE / correct_distance) * game->dist_proj_plane;
		texture = game->map.textures[game->rays[i].texture_id];
		draw_wall_texture(game, texture, wall_height, i);
		i++;
	}
}

static void	draw_wall_texture(t_game *game, mlx_texture_t *texture,
	double wall_height, int i)
{
	int				texture_offset_x;
	int				texture_offset_y;
	int				wall_top_y;
	int				wall_bottom_y;

	if (game->rays[i].was_hit_vertical)
		texture_offset_x = (int) game->rays[i].y % TILE_SIZE;
	else
		texture_offset_x = (int) game->rays[i].x % TILE_SIZE;
	wall_top_y = (game->map.height / 2) - (wall_height / 2);
	if (wall_top_y < 0)
		wall_top_y = 0;
	wall_bottom_y = (game->map.height / 2) + (wall_height / 2);
	if (wall_bottom_y > game->map.height)
		wall_bottom_y = game->map.height;
	while (wall_top_y < wall_bottom_y)
	{
		texture_offset_y = (wall_top_y + (wall_height / 2)
				- (game->map.height / 2))
			* ((float)texture->height / wall_height);
		mlx_put_pixel(game->graphic.img, i, wall_top_y,
			texture_pixel_color(texture, texture_offset_x, texture_offset_y));
		wall_top_y++;
	}
}

static int32_t	texture_pixel_color(mlx_texture_t *texture,
	int texture_offset_x, int texture_offset_y)
{
	uint32_t	pixel_index;
	int32_t		color;

	pixel_index = (texture_offset_y * texture->width + texture_offset_x) * 4;
	color = ft_pixel(texture->pixels[pixel_index],
			texture->pixels[pixel_index + 1],
			texture->pixels[pixel_index + 2],
			texture->pixels[pixel_index + 3]);
	return (color);
}
