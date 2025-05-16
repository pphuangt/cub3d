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

void	ft_error(t_game *game)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	game_terminate(game);
	exit(EXIT_FAILURE);
}

void	setup(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	setup_map(game);
	graphic->window = mlx_init(graphic->width, graphic->height, TITLE, false);
	if (!graphic->window)
		ft_error(game);
	render_map(game);
	mlx_key_hook(graphic->window, esc_exit, game);
	mlx_close_hook(graphic->window, close_hook, game);
}

void	render(t_game *game)
{
	mlx_loop(game->graphic.window);
	mlx_terminate(game->graphic.window);
}

int32_t	main(void)
{
	t_game	game;

	setup(&game);
	render(&game);
	return (EXIT_SUCCESS);
}
