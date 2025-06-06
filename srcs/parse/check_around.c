/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-04 15:49:14 by hg                #+#    #+#             */
/*   Updated: 2025-06-04 15:49:14 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_udr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		|| game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
		free_and_exit(game, "Invalid map: missing walls around tile");
}

void	check_udl(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		|| game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1')
		free_and_exit(game, "Invalid map: missing walls around tile");
}

void	check_dlr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
		free_and_exit(game, "Invalid map: missing walls around tile");
}

void	check_ulr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
		free_and_exit(game, "Invalid map: missing walls around tile");
}

void	check_udlr(t_game *game, int x, int y)
{
	if (game->input.map[x + ((y - 1) * game->input.col_count)] != '1'
		|| game->input.map[x + ((y + 1) * game->input.col_count)] != '1'
		|| game->input.map[(x - 1) + (y * game->input.col_count)] != '1'
		|| game->input.map[(x + 1) + (y * game->input.col_count)] != '1')
		free_and_exit(game, "Invalid map: missing walls around tile");
}
