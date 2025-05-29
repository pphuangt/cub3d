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

int	g_wall[ROW][COL] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	setup_map(t_game *game)
{
	t_graphic	*graphic;
	t_map		*map;

	graphic = &game->graphic;
	graphic->height = TILEY * ROW;
	graphic->width = TILEX * COL;
	map = &game->map;
	map->col = COL;
	map->row = ROW;
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
				color(GREY);
			else
				color(WHITE);
			rect(x * TILEX, y * TILEY, TILEX, TILEY);
			x++;
		}
		y++;
	}
}

bool	has_wall_at(uint32_t x, uint32_t y)
{
	return (g_wall[y / TILEX][x / TILEX]);
}
