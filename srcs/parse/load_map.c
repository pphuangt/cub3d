/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 07:24:36 by hg                #+#    #+#             */
/*   Updated: 2025-06-03 07:24:36 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*set_spaces(char *line, t_game *game)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(line);
	while (len < game->input.col_count)
	{
		temp = line;
		line = ft_strjoin(line, " ");
		check_malloc(line, game);
		free(temp);
		len++;
	}
	return (line);
}

static void	fill_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	line = skip_texture_lines(fd, game);
	while (1)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		check_malloc(line, game);
		free(tmp);
		tmp = game->input.map;
		if (ft_strlen(line) < game->input.col_count)
			line = set_spaces(line, game);
		game->input.map = ft_strjoin(game->input.map, line);
		check_malloc(game->input.map, game);
		free(tmp);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	return (0);
}

void	load_and_validate_map(char *filename, t_game *game)
{
	fill_map(filename, game);
	check_map(game);
}
