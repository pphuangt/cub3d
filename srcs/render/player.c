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

static bool	is_walkable(double x1, double y1, double x2, double y2);

void	setup_player(t_game	*game)
{
	t_player	*player;

	player = &game->player;
	player->x = POSX * TILE_SIZE - TILE_SIZE / 2;
	player->y = POSY * TILE_SIZE - TILE_SIZE / 2;
	player->move_direction = 0;
	player->strafe_direction = 0;
	player->turn_direction = 0;
	player->rotation_angle = M_PI / 2;
	player->move_speed = 100;
	player->turn_speed = 60 * (M_PI / 180);
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	color(BLUE);
	circle(round(player->x), round(player->y), 6);
}

void	update_player(t_game *game)
{
	t_player	*player;
	double		move_step;
	double		strafe_step;
	double		x;
	double		y;

	player = &game->player;
	player->rotation_angle += player->turn_direction
		* player->turn_speed * game->delta_time;
	normalize_angle(&player->rotation_angle);
	move_step = player->move_direction * player->move_speed * game->delta_time;
	strafe_step = player->strafe_direction
		* player->move_speed * game->delta_time;
	x = player->x + cos(player->rotation_angle) * move_step
		+ cos(player->rotation_angle + PI_2) * strafe_step;
	y = player->y + sin(player->rotation_angle) * move_step
		+ sin(player->rotation_angle + PI_2) * strafe_step;
	if (is_walkable(player->x, player->y, x, y))
	{
		player->x = x;
		player->y = y;
	}
}

static bool	is_walkable(double x1, double y1, double x2, double y2)
{
	int curr_tile_x;
	int curr_tile_y;
	int	dest_tile_x;
	int	dest_tile_y;

	if (!map_is_inside(x2, y2) || map_has_wall_at(x2, y2))
		return false;
	curr_tile_x = (int)(x1 / TILE_SIZE);
	curr_tile_y = (int)(y1 / TILE_SIZE);
	dest_tile_x = (int)(x2 / TILE_SIZE);
	dest_tile_y = (int)(y2 / TILE_SIZE);
	if (curr_tile_x != dest_tile_x && curr_tile_y != dest_tile_y)
	{
		if (map_has_wall_at(x2, y1) || map_has_wall_at(x1, y2))
			return false;
	}

	return true;
}
