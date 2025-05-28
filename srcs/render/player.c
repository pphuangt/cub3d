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

static void	move(t_player *player, enum e_dir dir);
static void	rotate(t_player *player, enum e_dir dir);

void	setup_player(t_game	*game)
{
	t_player	*player;

	player = &game->player;
	player->x = POSX * TILEX - TILEX / 2;
	player->y = POSY * TILEY - TILEY / 2;
	player->angle = 0;
}

void	render_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	color(BLUE);
	circle(player->x, player->y, 6);
	color(RED);
	line(player->x,
		 player->y,
		 player->x + 100 * cos(player->angle),
		 player->y + 100 * sin(player->angle));
}

void	update_player(void *param)
{
	t_game		*game;
	t_graphic	*graphic;
	t_player	*player;

	game = (t_game *)param;
	graphic = &game->graphic;
	player = &game->player;
	if (mlx_is_key_down(graphic->window, MLX_KEY_W))
		move(player, UP);
	if (mlx_is_key_down(graphic->window, MLX_KEY_S))
		move(player, DOWN);
	if (mlx_is_key_down(graphic->window, MLX_KEY_D))
		move(player, RIGHT);
	if (mlx_is_key_down(graphic->window, MLX_KEY_A))
		move(player, LEFT);
	if (mlx_is_key_down(graphic->window, MLX_KEY_RIGHT))
		rotate(player, RIGHT);
	if (mlx_is_key_down(graphic->window, MLX_KEY_LEFT))
		rotate(player, LEFT);
	update(game);
}

static void	move(t_player *player, enum e_dir dir)
{
	double	x;
	double	y;
	double move_speed;

	x = player->x;
	y = player->y;
	move_speed = MOVE_SPEED;
	if (dir == UP)
	{
		x = (double)player->x + move_speed * cos(player->angle);
		y = (double)player->y + move_speed * sin(player->angle);
	} else if (dir == DOWN)
	{
		x = (double)player->x - move_speed * cos(player->angle);
		y = (double)player->y - move_speed * sin(player->angle);
	}
	player->x = x;
	player->y = y;
}

static void	rotate(t_player *player, enum e_dir dir)
{
	double	angle;

	if (dir == RIGHT)
		angle = player->angle + ROTATE_SPEED;
	else
		angle = player->angle - ROTATE_SPEED;
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	player->angle = angle;
}