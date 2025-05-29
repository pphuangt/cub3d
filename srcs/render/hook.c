/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:09:34 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/17 11:09:35 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	close_hook(void *param);
static void	process_input(mlx_key_data_t key_data, void *param);
static void	key_pressed(t_player *player, keys_t key);
static void	key_release(t_player *player, keys_t key);

void	setup_hook(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	mlx_key_hook(graphic->window, process_input, game);
	mlx_loop_hook(graphic->window, update, game);
	mlx_close_hook(graphic->window, close_hook, game);
}

static void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	terminate(game);
}

static void	process_input(mlx_key_data_t key_data, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (key_data.key == MLX_KEY_ESCAPE)
		terminate(game);
	else if (key_data.action == MLX_PRESS)
		key_pressed(&game->player, key_data.key);
	else if (key_data.action == MLX_RELEASE)
		key_release(&game->player, key_data.key);
}

static void	key_pressed(t_player *player, keys_t key)
{
	if (key == MLX_KEY_W)
		player->move_direction = 1;
	else if (key == MLX_KEY_A)
		player->move_direction = -1;
	else if (key == MLX_KEY_RIGHT)
		player->turn_direction = 1;
	else if (key == MLX_KEY_LEFT)
		player->turn_direction = -1;
}

static void	key_release(t_player *player, keys_t key)
{
	if (key == MLX_KEY_W)
		player->move_direction = 0;
	else if (key == MLX_KEY_A)
		player->move_direction = 0;
	else if (key == MLX_KEY_RIGHT)
		player->turn_direction = 0;
	else if (key == MLX_KEY_LEFT)
		player->turn_direction = 0;
}
