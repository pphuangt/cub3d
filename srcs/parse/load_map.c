/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:35:44 by plesukja          #+#    #+#             */
/*   Updated: 2025/06/10 10:09:41 by plesukja         ###   ########.fr       */
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
	line = skip_texture_lines(fd);
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
}

void	load_and_validate_map(char *filename, t_game *game)
{
	fill_map(filename, game);
	check_map(game);
}
