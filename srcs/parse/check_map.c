/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 07:09:03 by hg                #+#    #+#             */
/*   Updated: 2025/06/07 11:12:55 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_bottom_walls(t_game *game)
{
	size_t	i;
	size_t	row_cnt;
	size_t	col_cnt;

	row_cnt = game->input.row_count;
	col_cnt = game->input.col_count;
	i = 0;
	while (i < game->input.col_count)
	{
		if (game->input.map[i] != '1' && game->input.map[i] != ' ')
		{
			printf("Invalid top wall at index %zu: '%c'\n",
				i, game->input.map[i]);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < game->input.col_count)
	{
		if (game->input.map[i + ((row_cnt - 1) * col_cnt)] != '1'
			&& game->input.map[i + ((row_cnt - 1) * col_cnt)] != ' ')
		{
			printf("Invalid bottom wall at index %zu: '%c'\n",
				i + ((row_cnt - 1) * col_cnt), game->input.map[i + ((row_cnt - 1) * col_cnt)]);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	check_around_tiles(t_game *game, size_t x, size_t y)
{
	if (x == 0)
		check_udr(game, x, y);
	else if (x == game->input.col_count - 1)
		check_udl(game, x, y);
	// else if (y == 0)
	// 	check_dlr(game, x, y);
	// else if (y == game->input.row_count - 1)
	// 	check_ulr(game, x, y);
	else
		check_udlr(game, x, y);
}

static void	set_start_pos(t_game *game, int x, int y)
{
	if (game->input.posx != 0 || game->input.posy != 0)
		free_and_exit(game, "Map has multiple starting positions");
	game->input.posx = x;
	game->input.posy = y;
	game->input.pos_dirctn = game->input.map[x + (y * game->input.col_count)];
	game->input.map[x + (y * game->input.col_count)] = '0';
}

static int	check_each_tiles_and_set_dir(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (y < game->input.row_count - 1)
	{
		x = 0;
		while (x < game->input.col_count)
		{
			if (game->input.map[x + (y * game->input.col_count)] == 'N'
				|| game->input.map[x + (y * game->input.col_count)] == 'S'
				|| game->input.map[x + (y * game->input.col_count)] == 'W'
				|| game->input.map[x + (y * game->input.col_count)] == 'E')
				set_start_pos(game, x, y);
			else
				check_around_tiles(game, x, y);
			x++;
		}
		y++;
	}
	// if (game->input.pos_dirctn == 'N')
	// 	return (-1);
	return (0);
}

void	check_map(t_game *game)
{
	game->input.posx = 0;
	game->input.posy = 0;
	game->input.pos_dirctn = 'N';
	if (check_top_bottom_walls(game) != 0)
		free_and_exit(game, "Map must be surrounded by walls");
	if (check_each_tiles_and_set_dir(game) != 0)
		free_and_exit(game, "Map has invalid tiles");
}
