#include "cub3d.h"

static t_ray	horz_wall_hit(double xintercept, double yintercept,
					double xstep, double ystep);
static t_ray	vert_wall_hit(double xintercept, double yintercept,
					double xstep, double ystep);

t_ray	horizontal_intersection(t_player *player, double ray_angle)
{
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	yintercept = floor(player->y / TILEY) * TILEY;
	if (ray_facing_down(ray_angle))
		yintercept += TILEY;
	xintercept = player->x + (yintercept - player->y) / tan(ray_angle);
	ystep = TILEY;
	if (ray_facing_up(ray_angle))
		ystep *= -1;
	xstep = ystep / tan(ray_angle);
	if (ray_facing_left(ray_angle) && xstep > 0)
		xstep *= -1;
	if (ray_facing_right(ray_angle) && xstep < 0)
		xstep *= -1;
	return (horz_wall_hit(xintercept, yintercept, xstep, ystep));
}

t_ray	vertical_intersection(t_player *player, double ray_angle)
{
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	xintercept = floor(player->x / TILEX) * TILEX;
	if (ray_facing_right(ray_angle))
		xintercept += TILEX;
	yintercept = player->y + (xintercept - player->x) * tan(ray_angle);
	xstep = TILEX;
	if (ray_facing_left(ray_angle))
		xstep *= -1;
	ystep = xstep * tan(ray_angle);
	if (ray_facing_down(ray_angle) && ystep < 0)
		ystep *= -1;
	if (ray_facing_up(ray_angle) && ystep > 0)
		ystep *= -1;
	return (vert_wall_hit(xintercept, yintercept, xstep, ystep));
}

static t_ray	horz_wall_hit(double xintercept, double yintercept,
	double xstep, double ystep)
{
	double	next_touch_x;
	double	next_touch_y;
	double	x_to_check;
	double	y_to_check;

	next_touch_x = xintercept;
	next_touch_y = yintercept;
	while (is_inside_map(next_touch_x, next_touch_y))
	{
		x_to_check = next_touch_x;
		y_to_check = next_touch_y - (ystep < 0);
		if (has_wall_at(x_to_check, y_to_check))
			return ((t_ray){0, next_touch_x, next_touch_y, 0, true});
		next_touch_x += xstep;
		next_touch_y += ystep;
	}
	return ((t_ray){0});
}

static t_ray	vert_wall_hit(double xintercept, double yintercept,
	double xstep, double ystep)
{
	double	next_touch_x;
	double	next_touch_y;
	double	x_to_check;
	double	y_to_check;

	next_touch_x = xintercept;
	next_touch_y = yintercept;
	while (is_inside_map(next_touch_x, next_touch_y))
	{
		x_to_check = next_touch_x - (xstep < 0);
		y_to_check = next_touch_y;
		if (has_wall_at(x_to_check, y_to_check))
			return ((t_ray){0, next_touch_x, next_touch_y, 0, true});
		next_touch_x += xstep;
		next_touch_y += ystep;
	}
	return ((t_ray){0});
}
