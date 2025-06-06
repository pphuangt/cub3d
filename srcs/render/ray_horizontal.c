/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:11:26 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/03 08:11:27 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ray	horz_wall_hit(double xintercept, double yintercept,
					double xstep, double ystep);

t_ray	horizontal_intersection(t_player *player, double ray_angle)
{
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	yintercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray_facing_down(ray_angle))
		yintercept += TILE_SIZE;
	xintercept = player->x + (yintercept - player->y) / tan(ray_angle);
	ystep = TILE_SIZE;
	if (ray_facing_up(ray_angle))
		ystep *= -1;
	xstep = ystep / tan(ray_angle);
	if (ray_facing_left(ray_angle) && xstep > 0)
		xstep *= -1;
	if (ray_facing_right(ray_angle) && xstep < 0)
		xstep *= -1;
	return (horz_wall_hit(xintercept, yintercept, xstep, ystep));
}

static t_ray	horz_wall_hit(double xintercept, double yintercept,
	double xstep, double ystep)
{
	double	next_touch_x;
	double	next_touch_y;

	next_touch_x = xintercept;
	next_touch_y = yintercept;
	while (map_is_inside(next_touch_x, next_touch_y))
	{
		if (map_has_wall_at(next_touch_x, next_touch_y - (ystep < 0)))
			return ((t_ray){0, next_touch_x, next_touch_y, 0, 0, true, false});
		next_touch_x += xstep;
		next_touch_y += ystep;
	}
	return ((t_ray){0});
}
