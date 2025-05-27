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

static void	move(t_player *player, uint32_t x, uint32_t y);

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
	color(RED);
	circle(player->x, player->y, 6);
}

void	update_player(void *param)
{
	t_game		*game;
	t_graphic	*graphic;
	t_player	*player;

	game = (t_game *)param;
	graphic = &game->graphic;
	player = &game->player;
	if (mlx_is_key_down(graphic->window, MLX_KEY_UP))
		move(player, player->x, player->y - 2);
	if (mlx_is_key_down(graphic->window, MLX_KEY_DOWN))
		move(player, player->x, player->y + 2);
	if (mlx_is_key_down(graphic->window, MLX_KEY_RIGHT))
		move(player, player->x + 2, player->y);
	if (mlx_is_key_down(graphic->window, MLX_KEY_LEFT))
		move(player, player->x - 2, player->y);
	update(game);
}

static void	move(t_player *player, uint32_t x, uint32_t y)
{
	if (has_wall(x, y))
		return ;
	player->x = x;
	player->y = y;
}
