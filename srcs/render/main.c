/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:29:50 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/05 13:29:52 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup(t_game *game);
static void	run(t_game *game);
static void	render(t_game *game);

int32_t	main(void)
{
	t_game	game;

	setup(&game);
	run(&game);
	return (EXIT_SUCCESS);
}

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->delta_time = game->graphic.window->delta_time;
	render(game);
}

static void	render(t_game *game)
{
	render_map(game);
	render_player(game);
}

static void	setup(t_game *game)
{
	setup_map(game);
	setup_player(game);
	setup_graphic(game);
	setup_draw(game);
	setup_hook(game);
}

static void	run(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	mlx_image_to_window(graphic->window, graphic->img, 0, 0);
	mlx_loop(graphic->window);
	mlx_terminate(graphic->window);
}
