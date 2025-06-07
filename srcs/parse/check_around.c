/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:49:14 by hg                #+#    #+#             */
/*   Updated: 2025/06/07 11:42:56 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_udr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'E'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'E'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != '1'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != ' '
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != '0'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'N'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'S'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'W'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'E')
		free_and_exit(game, "Invalid map: missing walls around tile_udr");
}

// void	check_udr(t_game *game, int x, int y)
// {
// 	if (game->input.map[x + ((y - 1) * game->input.col_count)] == ' '
// 		|| game->input.map[x + ((y + 1) * game->input.col_count)] != ' '
// 		|| game->input.map[(x + 1) + (y * game->input.col_count)] != ' ')
// 		free_and_exit(game, "Invalid map: missing walls around tile_udr");
// }

void	check_udl(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'E'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'E'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != ' '
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != '0'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'N'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'S'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'W'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'E')
		free_and_exit(game, "Invalid map: missing walls around tile_udl");
}

// void	check_dlr(t_game *game, int x, int y)
// {
// 	if (game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
// 		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
// 		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
// 		free_and_exit(game, "Invalid map: missing walls around tile");
// }

// void	check_ulr(t_game *game, int x, int y)
// {
// 	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
// 		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
// 		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
// 		free_and_exit(game, "Invalid map: missing walls around tile");
// }

void	check_udlr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y - 1) * game->input.col_count)] != 'E'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != ' '
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != '0'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'N'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'S'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'W'
		&& game->input.map[x + ((y + 1) * game->input.col_count)] != 'E'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != ' '
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != '0'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'N'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'S'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'W'
		&& game->input.map[(x - 1) + (y * game->input.col_count)] != 'E'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != '1'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != ' '
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != '0'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'N'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'S'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'W'
		&& game->input.map[(x + 1) + (y * game->input.col_count)] != 'E')
		free_and_exit(game, "Invalid map: missing walls around tile_uldr");
}
