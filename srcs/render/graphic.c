#include "cub3d.h"

void	setup_graphic(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	graphic->window = mlx_init(graphic->width, graphic->height, TITLE, false);
	if (!graphic->window)
		ft_error(game);
	graphic->img[0] = mlx_new_image(
			graphic->window,
			graphic->width,
			graphic->height);
	if (!graphic->img[0])
		ft_error(game);
	graphic->img[1] = mlx_new_image(
			graphic->window,
			graphic->width,
			graphic->height);
	if (!graphic->img[1])
		ft_error(game);
}

void	terminate(t_game *game)
{
	mlx_close_window(game->graphic.window);
}
