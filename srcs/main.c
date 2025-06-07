/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:29:50 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/07 09:51:28 by plesukja         ###   ########.fr       */
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

// int32_t	main(int ac, char **av)
// {
// 	t_game	game;

// 	if (ac != 2)
// 	{
// 		ft_putendl_fd("Error\nUsage: ./cub3d <map.cub>", STDERR_FILENO);
// 		return (EXIT_FAILURE);
// 	}
// 	parse_map_file(av[1], &game);
// 	setup(&game);
// 	render(&game);
// 	return (EXIT_SUCCESS);
// }

//-------Test Code for Parsing Textures and Colors-------
int main(int argc, char **argv)
{
    t_game game = {0};

    if (argc != 2)
    {
        printf("Usage: %s <config_file>\n", argv[0]);
        return (1);
    }

    // Call your parser here (textures, colors, etc.)
	parse_map_file(argv[1], &game);

    // Print the parsed data
    printf("NO texture path: %s\n", game.input.no_path);
    printf("SO texture path: %s\n", game.input.so_path);
    printf("WE texture path: %s\n", game.input.we_path);
    printf("EA texture path: %s\n", game.input.ea_path);
    printf("Floor color string: %s\n", game.input.f_color);
    printf("Ceiling color string: %s\n", game.input.c_color);
    printf("Floor color int: %d\n", game.input.f_color_int);
    printf("Ceiling color int: %d\n", game.input.c_color_int);
	printf("row_count: %zu\n", game.input.row_count);
	printf("col_count: %zu\n", game.input.col_count);
    // Free allocated memory
    free_input_memory(&game);

    return (0);
}

