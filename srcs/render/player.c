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

static bool	is_walkable(double x, double y);
static void	set_player_position(t_player *player, double new_x, double new_y);

void	setup_player(t_game	*game)
{
	t_player	*player;
	t_input		*input;

	player = &game->player;
	input = &game->input;
	player->x = (input->posx + 1) * TILE_SIZE - TILE_SIZE / 2;
	player->y = (input->posy + 1) * TILE_SIZE - TILE_SIZE / 2;
	player->move_direction = 0;
	player->strafe_direction = 0;
	player->turn_direction = 0;
	player->rotation_angle = PI_2;
	player->move_speed = 100;
	player->turn_speed = 60 * (M_PI / 180);
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	color(BLUE);
	circle(round(player->x * MINIMAP_SCALE),
		round(player->y * MINIMAP_SCALE),
		PLAYER_POINT);
}

void	update_player(t_game *game)
{
	t_player	*player;
	double		move_step;
	double		strafe_step;
	double		new_x;
	double		new_y;

	player = &game->player;
	player->rotation_angle += player->turn_direction
		* player->turn_speed * game->delta_time;
	normalize_angle(&player->rotation_angle);
	move_step = player->move_direction * player->move_speed * game->delta_time;
	strafe_step = player->strafe_direction
		* player->move_speed * game->delta_time;
	new_x = player->x + cos(player->rotation_angle) * move_step
		+ cos(player->rotation_angle + PI_2) * strafe_step;
	new_y = player->y + sin(player->rotation_angle) * move_step
		+ sin(player->rotation_angle + PI_2) * strafe_step;
	set_player_position(player, new_x, new_y);
}

static void	set_player_position(t_player *player, double new_x, double new_y)
{
	if (is_walkable(new_x, new_y))
	{
		player->x = new_x;
		player->y = new_y;
	}
	else if (is_walkable(new_x, player->y))
		player->x = new_x;
	else if (is_walkable(player->x, new_y))
		player->y = new_y;
}

static bool	is_walkable(double x, double y)
{
	if (map_has_wall_at(x + PLAYER_WALL_GAP, y)
		|| map_has_wall_at(x - PLAYER_WALL_GAP, y)
		|| map_has_wall_at(x, y + PLAYER_WALL_GAP)
		|| map_has_wall_at(x, y - PLAYER_WALL_GAP)
		|| map_has_wall_at(x + PLAYER_WALL_GAP, y + PLAYER_WALL_GAP)
		|| map_has_wall_at(x - PLAYER_WALL_GAP, y + PLAYER_WALL_GAP)
		|| map_has_wall_at(x + PLAYER_WALL_GAP, y - PLAYER_WALL_GAP)
		|| map_has_wall_at(x - PLAYER_WALL_GAP, y - PLAYER_WALL_GAP))
		return (false);
	return (true);
}
