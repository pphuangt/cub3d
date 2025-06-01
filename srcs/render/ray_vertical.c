#include "cub3d.h"

static t_ray	vert_wall_hit(double xintercept, double yintercept,
					double xstep, double ystep);

t_ray	vertical_intersection(t_player *player, double ray_angle)
{
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	xintercept = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray_facing_right(ray_angle))
		xintercept += TILE_SIZE;
	yintercept = player->y + (xintercept - player->x) * tan(ray_angle);
	xstep = TILE_SIZE;
	if (ray_facing_left(ray_angle))
		xstep *= -1;
	ystep = xstep * tan(ray_angle);
	if (ray_facing_down(ray_angle) && ystep < 0)
		ystep *= -1;
	if (ray_facing_up(ray_angle) && ystep > 0)
		ystep *= -1;
	return (vert_wall_hit(xintercept, yintercept, xstep, ystep));
}

static t_ray	vert_wall_hit(double xintercept, double yintercept,
	double xstep, double ystep)
{
	double	next_touch_x;
	double	next_touch_y;

	next_touch_x = xintercept;
	next_touch_y = yintercept;
	while (map_is_inside(next_touch_x, next_touch_y))
	{
		if (map_has_wall_at(next_touch_x - (xstep < 0), next_touch_y))
			return ((t_ray){0, next_touch_x, next_touch_y, 0, true});
		next_touch_x += xstep;
		next_touch_y += ystep;
	}
	return ((t_ray){0});
}
