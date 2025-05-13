#include "cub3d.h"

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game_terminate(game);
}

void	esc_exit(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(game);
}
