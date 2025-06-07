/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:36:48 by plesukja          #+#    #+#             */
/*   Updated: 2025/06/07 14:36:50 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free_and_exit(game, "Invalid texture path");
	if (check_texture_filename(tmp, game))
		free_and_exit(game, "Invalid texture filename");
	path = tmp[1];
	if (strcmp(dir, "NO") == 0)
		load_text_path(&game->input.no_path, path, "Can't open NO_text", game);
	else if (strcmp(dir, "SO") == 0)
		load_text_path(&game->input.so_path, path, "Can't open SO_text", game);
	else if (strcmp(dir, "WE") == 0)
		load_text_path(&game->input.we_path, path, "Can't open WE_text", game);
	else if (strcmp(dir, "EA") == 0)
		load_text_path(&game->input.ea_path, path, "Can't open EA_text", game);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

int	parse_texture(char *filename, t_game *game)
{
	int		fd;
	char	*line;

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
		free(line);
	}
	close(fd);
	return (0);
}
