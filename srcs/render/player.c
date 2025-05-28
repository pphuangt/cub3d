/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:09:44 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/17 11:09:46 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_player(t_game	*game)
{
	t_player	*player;

	player = &game->player;
	player->x = POSX * TILEX - TILEX / 2;
	player->y = POSY * TILEY - TILEY / 2;
	player->move_direction = 0;
	player->turn_direction = 0;
	player->rotate_angle = M_PI / 2;
	player->move_speed = 100;
	player->turn_speed = 30 * (M_PI / 180);
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	color(BLUE);
	circle(player->x, player->y, 6);
}

void	update_player(void *param)
{
	(void)param;
}