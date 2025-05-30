#include "cub3d.h"

static void		cast_ray(t_game *game, double ray_angle, int strip_id);

void	setup_ray(t_game *game)
{
	static t_ray	static_rays[2048];

	game->rays = static_rays;
	game->dist_proj_plane = ((double)game->graphic.width / 2.0)
		/ (tan(FOV_ANGLE / 2.0));
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

double	distance_between_points(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	cast_rays(t_game *game)
{
	t_player	*player;
	double		ray_angle;
	int			num_rays;
	int			i;

	player = &game->player;
	ray_angle = player->rotation_angle - (FOV_ANGLE / 2);
	num_rays = game->graphic.width;
	i = 0;
	while (i < num_rays)
	{
		cast_ray(game, ray_angle, i);
		ray_angle += FOV_ANGLE / num_rays;
		i++;
	}
}

static void	cast_ray(t_game *game, double ray_angle, int strip_id)
{
	t_player	*player;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;

	normalize_angle(&ray_angle);
	player = &game->player;
	// horizontal intersection
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

	bool foundHorzWallHit = false;
	double horzWallHitX = 0;
	double horzWallHitY = 0;

	double nextHorzTouchX = xintercept;
	double nextHorzTouchY = yintercept;

	// Increment xstep and ystep until we find a wall
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= game->graphic.width && nextHorzTouchY >= 0 && nextHorzTouchY <= game->graphic.height) {
		if (has_wall_at(nextHorzTouchX, nextHorzTouchY + (ray_facing_up(ray_angle) ? -1 : 0))) {
			foundHorzWallHit = true;
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			break;
		} else {
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}
	}

	// vertical intersection
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

	bool foundVertWallHit = false;
	double vertWallHitX = 0;
	double vertWallHitY = 0;
	double nextVertTouchX = xintercept;
	double nextVertTouchY = yintercept;

	// Increment xstep and ystep until we find a wall
	while (nextVertTouchX >= 0 && nextVertTouchX <= game->graphic.width && nextVertTouchY >= 0 && nextVertTouchY <= game->graphic.height) {
		if (has_wall_at(nextVertTouchX + (ray_facing_left(ray_angle) ? -1 : 0), nextVertTouchY)) {
			foundVertWallHit = true;
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			break;
		} else {
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}

	// compare
	double horzHitDistance = (foundHorzWallHit)
		? distance_between_points(player->x, player->y, horzWallHitX, horzWallHitY)
		: INT_MAX;
	double vertHitDistance = (foundVertWallHit)
		? distance_between_points(player->x, player->y, vertWallHitX, vertWallHitY)
		: INT_MAX;

	if (vertHitDistance < horzHitDistance)
	{
		game->rays[strip_id].x = vertWallHitX;
		game->rays[strip_id].y = vertWallHitY;
		game->rays[strip_id].distance = vertHitDistance;
		game->rays[strip_id].angle = ray_angle;
	} else {
		game->rays[strip_id].x = horzWallHitX;
		game->rays[strip_id].y = horzWallHitY;
		game->rays[strip_id].distance = horzHitDistance;
		game->rays[strip_id].angle = ray_angle;
	}
}