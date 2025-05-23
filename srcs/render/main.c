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
static void	render(t_game *game);

int32_t	main(void)
{
	t_game	game;

	setup(&game);
	render(&game);
	return (EXIT_SUCCESS);
}

void	ft_error(t_game *game)
{
	ft_putendl_fd("Error\n", STDERR_FILENO);
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	terminate(game);
	exit(EXIT_FAILURE);
}

static void	setup(t_game *game)
{
	setup_map(game);
	setup_player(game);
	setup_graphic(game);
	setup_draw(game);
	setup_hook(game);
}

static void	render(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	render_map(game);
	render_player(game);
	mlx_image_to_window(graphic->window, graphic->img[0], 0, 0);
	mlx_loop(graphic->window);
	mlx_terminate(graphic->window);
}
