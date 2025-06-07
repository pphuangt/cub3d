/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:34:43 by plesukja          #+#    #+#             */
/*   Updated: 2025/06/07 14:34:46 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_udr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] == ' '
		|| game->input.map[x + ((y + 1) * game->input.col_count)] == ' '
		|| game->input.map[(x + 1) + (y * game->input.col_count)] == ' ')
		free_and_exit(game, "Invalid map: missing walls around tile_udr");
}

void	check_udl(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] == ' '
		&& game->input.map[x + ((y + 1) * game->input.col_count)] == ' '
		&& game->input.map[(x - 1) + (y * game->input.col_count)] == ' ')
		free_and_exit(game, "Invalid map: missing walls around tile_udl");
}

void	check_udlr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] == ' '
		|| game->input.map[x + ((y + 1) * game->input.col_count)] == ' '
		|| game->input.map[(x - 1) + (y * game->input.col_count)] == ' '
		|| game->input.map[(x + 1) + (y * game->input.col_count)] == ' ')
		free_and_exit(game, "Invalid map: missing walls around tile_uldr");
}
