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

static void	render_ceil_floor(int width, int height);
static void	render_projection_wall(t_game *game, int width, int height);

void	render_wall(t_game *game)
{
	t_map	*map;

	map = &game->map;
	render_ceil_floor(map->width, map->height);
	render_projection_wall(game, map->width, map->height);
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

static void	render_projection_wall(t_game *game, int width, int height)
{
	double	wall_height;
	double	correct_distance;
	int		brightness;
	int		wall_color;
	int		i;

	i = 0;
	while (i < width)
	{
		correct_distance = game->rays[i].distance
			* cos(game->player.rotation_angle - game->rays[i].angle);
		wall_height = (TILE_SIZE / correct_distance) * game->dist_proj_plane;
		if (wall_height > height)
			wall_height = height;
		brightness = 200;
		if (game->rays[i].was_hit_vertical)
			brightness = 255;
		wall_color = ft_pixel(brightness, brightness, brightness, 255);
		border(wall_color);
		color(wall_color);
		rect(i, height / 2 - wall_height / 2, 1, wall_height);
		i++;
	}
}
