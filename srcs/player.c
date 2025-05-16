#include "cub3d.h"
#define COL 15
#define ROW 12
#define TILE_X 32
#define TILE_Y 32
#define POS_X ((TILE_X * COL + 1) / 2)
#define POS_Y ((TILE_Y * ROW + 1) / 2)
#define RADIUS 8
#define RED 0xFF0000FF
#include <math.h>

void	setup_player(t_game	*game)
{
	(void) game;
}

void	draw_player(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	double		center;

	center = RADIUS - 0.5f;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if ((x - center) * (x - center) + (y - center) * (y - center)
				<= (RADIUS * RADIUS))
				mlx_put_pixel(img, x, y, RED);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	t_graphic	*graphic;
	mlx_image_t	*img;

	graphic = &game->graphic;
	img = mlx_new_image(graphic->window, RADIUS * 2, RADIUS * 2);
	if (img == NULL)
		ft_error(game);
	draw_player(img);
	if (mlx_image_to_window(graphic->window, img, POS_X - RADIUS, POS_Y - RADIUS)
		== -1)
		ft_error(game);
}
