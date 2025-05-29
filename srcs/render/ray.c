#include "cub3d.h"

static void	cast_ray(t_game *game, double ray_angle, int strip_id);

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
	int			col;
	int			num_rays;
	double		ray_angle;

	player = &game->player;
	col = 0;
	num_rays = game->graphic.width;
	while (col < num_rays)
	{
		ray_angle = player->rotation_angle
			+ atan((col - num_rays / 2) / game->dist_proj_plane);
        cast_ray(game, ray_angle, col);
		col++;
	}
}

static void	cast_ray(t_game *game, double ray_angle, int strip_id)
{
	(void)game;
	(void)ray_angle;
	(void)strip_id;
}