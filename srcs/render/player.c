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

static void normalizeAngle(double *angle);

void	setup_player(t_game	*game)
{
	t_player	*player;

	player = &game->player;
	player->x = POSX * TILEX - TILEX / 2;
	player->y = POSY * TILEY - TILEY / 2;
	player->move_direction = 0;
	player->turn_direction = 0;
	player->rotation_angle = M_PI / 2;
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

void	update_player(t_game *game)
{
	t_player	*player;
	double		move_step;
	double		new_x;
	double		new_y;

	player = &game->player;
	player->rotation_angle += player->turn_direction * player->turn_speed * game->delta_time;
	normalizeAngle(&player->rotation_angle);
	move_step = player->move_direction * player->move_speed * game->delta_time;
	new_x = player->x + cos(player->rotation_angle) * move_step;
	new_y = player->y + sin(player->rotation_angle) * move_step;
	if (!has_wall_at(floor(new_x), floor(new_y))) {
		player->x = (uint32_t)new_x;
		player->y = (uint32_t)new_y;
	}
}

static void normalizeAngle(double *angle) {
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0) {
		*angle = TWO_PI + *angle;
	}
}
