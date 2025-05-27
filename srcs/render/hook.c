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
static void	esc_exit(mlx_key_data_t keydata, void *param);

void	setup_hook(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	mlx_key_hook(graphic->window, esc_exit, game);
	mlx_close_hook(graphic->window, close_hook, game);
	mlx_loop_hook(graphic->window, update_player, game);
}

static void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	terminate(game);
}

static void	esc_exit(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		terminate(game);
}
