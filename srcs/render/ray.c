/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:28:41 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/30 20:28:42 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cast_ray(t_game *game, double ray_angle, int strip_id);

void	setup_ray(t_game *game)
{
	static t_ray	static_rays[2048];

	game->rays = static_rays;
	game->dist_proj_plane = ((double)game->graphic.width / 2)
		/ (tan(FOV_ANGLE / 2));
}

void	render_ray(t_game *game)
{
	t_player	*player;
	t_ray		*rays;
	int			i;
	int			num_rays;

	player = &game->player;
	rays = game->rays;
	i = 0;
	color(RED);
	num_rays = game->graphic.width;
	while (i < num_rays)
	{
		line(player->x,
			player->y,
			rays[i].x,
			rays[i].y);
		i++;
	}
}

void	cast_rays(t_game *game)
{
	t_player	*player;
	double		ray_angle;
	int			num_rays;
	int			i;

	player = &game->player;
	num_rays = game->graphic.width;
	i = 0;
	while (i < num_rays)
	{
		ray_angle = player->rotation_angle
			+ atan((i - num_rays / 2) / game->dist_proj_plane);
		cast_ray(game, ray_angle, i);
		i++;
	}
}

static void	cast_ray(t_game *game, double ray_angle, int strip_id)
{
	t_player	*player;
	t_ray		horizontal;
	t_ray		vertical;

	normalize_angle(&ray_angle);
	player = &game->player;
	horizontal = horizontal_intersection(player, ray_angle);
	vertical = vertical_intersection(player, ray_angle);
	horizontal.distance = INFINITY;
	if (horizontal.found_wall_hit)
		horizontal.distance = distance_between_points(player->x, player->y,
				horizontal.x, horizontal.y);
	vertical.distance = INFINITY;
	if (vertical.found_wall_hit)
		vertical.distance = distance_between_points(player->x, player->y,
				vertical.x, vertical.y);
	if (vertical.distance < horizontal.distance)
		game->rays[strip_id] = vertical;
	else
		game->rays[strip_id] = horizontal;
	game->rays[strip_id].angle = ray_angle;
}
