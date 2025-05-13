#include "cub3d.h"

void	game_terminate(t_game *game)
{
	mlx_close_window(game->graphic.window);
}
