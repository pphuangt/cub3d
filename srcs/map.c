#include "cub3d.h"

#define GREY_COLOR 0xFF808080
#define ROW 12
#define COL 15

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
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

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
    ft_memcpy(map->wall, wall, sizeof(int) * map->row * map->col);
}

void	test(t_game *game)
{
    t_map	*map;
    int		count_wall;
    int		total_wall_pixel;

    map = &game->map;
    count_wall = 0;
    printf("row got: %d, expect: %d\n", map->row, ROW);
    printf("col got: %d, expect: %d\n", map->col, COL);
    for (int i = 0; i < map->row; i++) {
	for (int j = 0; j < map->col; j++) {
	    count_wall += wall[i][j];
	}
    }
    printf("wall got: %d, expect: %d\n", count_wall, 50);
    printf("tild_x got: %d, expect: %d\n", map->tile_x, WINDOW_WIDTH / COL);
    printf("tild_y got: %d, expect: %d\n", map->tile_y, WINDOW_HEIGHT / ROW);
    total_wall_pixel = 0;
    for (uint32_t i = 0; i < map->img->height; i++) {
	for (uint32_t j = 0; j < map->img->width; j++) {
	    int row = i / map->tile_y;
	    int col = j / map->tile_x;

	    if (row >= map->row) row = map->row - 1;
	    if (col >= map->col) col = map->col - 1;

	    if (map->wall[row][col] > 0)
		total_wall_pixel++;
	}
    }
    int expected_pixels = count_wall * map->tile_x * map->tile_y;
    printf("total wall pixel got: %d, expect: %d\n", total_wall_pixel, expected_pixels);
}

void	render_map(t_game *game)
{
    t_graphic	*graphic;
    t_map	*map;

    graphic = &game->graphic;
    map = &game->map;
    if (mlx_image_to_window(graphic->window, map->img, 0, 0) == -1)
	ft_error(game);
    test(game);
}

