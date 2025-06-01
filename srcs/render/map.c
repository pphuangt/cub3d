/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:09:40 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/17 11:09:41 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	map_collision(t_map *map, double x, double y, int operation);

int	g_wall[ROW][COL] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	setup_map(t_game *game)
{
	t_map		*map;

	map = &game->map;
	map->col = COL;
	map->row = ROW;
	map->width = TILE_SIZE * COL;
	map->height = TILE_SIZE * ROW;
	map_collision(map, 0, 0, 0);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;

	(void)game;
	y = 0;
	border(BLACK);
	while (y < ROW)
	{
		x = 0;
		while (x < COL)
		{
			if (g_wall[y][x] == 1)
				color(BLACK);
			else
				color(WHITE);
			rect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
			x++;
		}
		y++;
	}
}

bool	map_has_wall_at(double x, double y)
{
	return (map_collision(NULL, x, y, 2));
}

bool	map_is_inside(double x, double y)
{
	return (map_collision(NULL, x, y, 1));
}

static bool	map_collision(t_map *map, double x, double y, int operation)
{
	static t_map	*static_map = NULL;
	int				index_x;
	int				index_y;

	if (!static_map)
	{
		static_map = map;
		return (true);
	}
	if (operation == 1)
	{
		return (x >= 0 && x < static_map->width
			&& y >= 0 && y < static_map->height);
	}
	if (x < 0 || x >= static_map->width || y < 0 || y >= static_map->height)
		return (true);
	index_x = floor(x / TILE_SIZE);
	index_y = floor(y / TILE_SIZE);
	return (g_wall[index_y][index_x] != 0);
}
