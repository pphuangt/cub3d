#include "cub3d.h"

#define GREY_COLOR 0xFF808080
#define ROW 11
#define COL 15

void	set_map(t_game *game)
{
    t_graphic	*graphic;
    t_map	*map;

    graphic = &game->graphic;
    map = &game->map;
    map->img = mlx_new_image(graphic->window, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!map->img)
	ft_error(game);
    map->row = ROW;
    map->col = COL;
    map->tile_x = WINDOW_WIDTH / map->col;
    map->tile_y = WINDOW_HEIGHT / map->row;
    int wall[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    ft_memcpy(map->wall, wall, sizeof(int) * map->row * map->col);
}

void	render_map(t_game *game)
{
    t_graphic	*graphic;
    t_map		*map;

    graphic = &game->graphic;
    map = &game->map;
    if (mlx_image_to_window(graphic->window, map->img, 0, 0) == -1)
	ft_error(game);
    // draw
}

