#include "cub3d.h"

void	setup_draw(t_game *game)
{
	t_renderer	*renderer;

	renderer = &game->renderer;
	renderer->border = 0;
	renderer->color = 0;
	draw_rect(renderer, NULL);
	draw_line(renderer, NULL);
	draw_circle(renderer, NULL);
	draw_color(renderer, NULL, NULL);
}