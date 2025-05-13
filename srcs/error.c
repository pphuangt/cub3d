#include "cub3d.h"

void	ft_error(t_game *game)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	game_terminate(game);
	exit(EXIT_FAILURE);
}
