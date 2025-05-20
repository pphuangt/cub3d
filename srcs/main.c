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
	setup_player(game);
	graphic->window = mlx_init(graphic->width, graphic->height, TITLE, false);
	if (!graphic->window)
		ft_error(game);
	graphic->img = mlx_new_image(
			graphic->window,
			graphic->width,
			graphic->height);
	if (!graphic->img)
		ft_error(game);
	mlx_key_hook(graphic->window, esc_exit, game);
	mlx_close_hook(graphic->window, close_hook, game);
}

void	render(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	render_map(game);
	render_player(game);
	mlx_image_to_window(graphic->window, graphic->img, 0, 0);
	mlx_loop(graphic->window);
	mlx_terminate(graphic->window);
}

int32_t	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putendl_fd("Error\nUsage: ./cub3d <map.cub>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parse_map_file(av[1], &game);
	setup(&game);
	render(&game);
	return (EXIT_SUCCESS);
}
