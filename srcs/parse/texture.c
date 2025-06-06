/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 05:48:14 by hg                #+#    #+#             */
/*   Updated: 2025-06-03 05:48:14 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_texture(t_game *game)
{
	t_graphic	*alloced_texts;

	alloced_texts = (t_graphic *) malloc(TEXTURE_COUNT * sizeof(t_graphic));
	if (!alloced_texts)
		free_and_exit(game, "Error allocating memory for textures");
	game->input.textures = alloced_texts;
}

static void	load_text_path(char **text_path,
	char *path, const char *err_msg, t_game *game)
{
	char	*trimmed_path;
	int		fd;

	trimmed_path = ft_strtrim(path, " \n");
	if (!trimmed_path)
		free_and_exit(game, "Error: Invalid texture path");
	*text_path = trimmed_path;
	fd = open(trimmed_path, O_RDONLY);
	if (fd < 0)
		free_and_exit(game, err_msg);
	close(fd);
}

static void	get_texture_path(char *dir, char *line, t_game *game)
{
	char	**tmp;
	char	*path;

	tmp = ft_split(line, ' ');
	if (!tmp || !tmp[1])
		free_and_exit(game, "Error: Invalid texture path");
	if (check_texture_filename(tmp))
		free_and_exit(game, "Error: Invalid texture filename");
	path = tmp[1];
	if (dir == "NO")
		load_text_path(&game->input.no_path, path, "Can't open NO_text", game);
	else if (dir == "SO")
		load_text_path(&game->input.so_path, path, "Can't open SO_text", game);
	else if (dir == "WE")
		load_text_path(&game->input.we_path, path, "Can't open WE_text", game);
	else if (dir == "EA")
		load_text_path(&game->input.ea_path, path, "Can't open EA_text", game);
	else if (dir == "D")
		load_text_path(&game->input.door_path, path, "Can't open D_text", game);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

int	parse_texture(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO", 2) == 0)
			get_texture_path("NO", line, game);
		if (ft_strncmp(line, "SO", 2) == 0)
			get_texture_path("SO", line, game);
		if (ft_strncmp(line, "WE", 2) == 0)
			get_texture_path("WE", line, game);
		if (ft_strncmp(line, "EA", 2) == 0)
			get_texture_path("EA", line, game);
		if (ft_strncmp(line, "D", 1) == 0)
			get_texture_path("D", line, game);
		free(line);
	}
	close(fd);
	return (0);
}
