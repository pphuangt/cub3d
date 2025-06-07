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

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("Usage: ./cub3d <map file>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parse(argv[1], &game);
	setup(&game);
	run(&game);
	return (EXIT_SUCCESS);
}

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->delta_time = game->graphic.window->delta_time;
	update_player(game);
	cast_rays(game);
	render(game);
}

static void	render(t_game *game)
{
	render_wall(game);
	render_map(game);
	render_player(game);
	render_ray(game);
}

static void	setup(t_game *game)
{
	setup_map(game);
	setup_player(game);
	setup_graphic(game);
	setup_ray(game);
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
