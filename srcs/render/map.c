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

void	setup_map(t_game *game)
{
	t_map		*map;
	t_input		*input;

	map = &game->map;
	input = &game->input;
	map->wall = input->map;
	map->col = (int)input->col_count;
	map->row = (int)input->row_count;
	map->width = TILE_SIZE * map->col;
	map->height = TILE_SIZE * map->row;
	map_collision(map, 0, 0, 0);
	map->textures[0] = mlx_load_png(input->no_path);
	map->textures[1] = mlx_load_png(input->so_path);
	map->textures[2] = mlx_load_png(input->we_path);
	map->textures[3] = mlx_load_png(input->ea_path);
	if (!map->textures[0] || !map->textures[1]
		|| !map->textures[2] || !map->textures[3])
		ft_error(game);
}

void	render_map(t_game *game)
{
	t_map	*map;
	int		x;
	int		y;

	map = &game->map;
	y = 0;
	border(BLACK);
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->wall[y * map->col + x] == '1')
				color(BLACK);
			else
				color(WHITE);
			rect(round(x * TILE_SIZE * MINIMAP_SCALE),
				round(y * TILE_SIZE * MINIMAP_SCALE),
				round(TILE_SIZE * MINIMAP_SCALE),
				round(TILE_SIZE * MINIMAP_SCALE));
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
	return (map->wall[index_y * map->col + index_x] != '0');
}
