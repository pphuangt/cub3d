/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>           #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 08:03:57 by plesukja            #+#    #+#           */
/*   Updated: 2025-05-20 08:03:57 by plesukja            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_map_file(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_and_exit(game, "Error opening map file");
	close(fd);
}

static void	allocate_map_memory(t_game *game)
{
	int	total_cells;

	total_cells = game->input.row_count * game->input.col_count;
	game->input.map = ft_calloc((unsigned int)(total_cells), sizeof(char));
	if (!game->input.map)
		free_and_exit(game, "Error allocating memory for map");
}

static void	verify_start_position(t_game *game)
{
	if (game->input.posx == 0 || game->input.posy == 0)
		free_and_exit(game, "Map has no starting position");
}

void	parse_map_file(char *filename, t_game *game)
{
	open_map_file(filename, game);
	check_map_filename(filename, game);
	if (parse_texture(filename, game))
		free_and_exit(game, "Error parsing textures\n");
	if (parse_color_str(filename, game))
		free_and_exit(game, "Error parsing colors\n");
	convert_colors(game);
	get_map_info(filename, game);
	allocate_map_memory(game);
	load_and_validate_map(filename, game);
	verify_start_position(game);
}

void	parse(char *filename, t_game *game)
{
	parse_texture(filename, game);
	parse_color_str(filename, game);
	convert_colors(game);
}
