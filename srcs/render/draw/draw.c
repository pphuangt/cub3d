#include "cub3d.h"

void	setup_draw(t_game *game)
{
	draw_rect(game->graphic.img[0], NULL);
	draw_line(game->graphic.img[0], NULL);
	draw_circle(game->graphic.img[0], NULL);
}
