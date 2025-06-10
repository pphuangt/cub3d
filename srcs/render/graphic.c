/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:04:48 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:04:50 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_graphic(t_game *game)
{
	t_graphic	*graphic;
	t_map		*map;

	graphic = &game->graphic;
	map = &game->map;
	graphic->window = mlx_init(map->width, map->height, TITLE, false);
	if (!graphic->window)
		ft_error(game);
	graphic->img = mlx_new_image(
			graphic->window,
			map->width,
			map->height);
	if (!graphic->img)
		ft_error(game);
}

void	terminate(t_game *game)
{
	mlx_close_window(game->graphic.window);
	free_input_memory(game);
	mlx_delete_texture(game->map.textures[NORTH]);
	mlx_delete_texture(game->map.textures[SOUTH]);
	mlx_delete_texture(game->map.textures[WEST]);
	mlx_delete_texture(game->map.textures[EAST]);
}
