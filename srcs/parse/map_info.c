/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:35:55 by plesukja          #+#    #+#             */
/*   Updated: 2025/06/10 10:38:51 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_nok(char *line, t_game *game)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != ' ')
			return (1);
		i++;
	}
	if (i > game->input.col_count)
		game->input.col_count = i;
	return (0);
}

static void	check_line(char *line, t_game *game, int fd)
{
	if (line_nok(line, game))
	{
		free(line);
		line = get_next_line(fd);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		free_and_exit(game, "Invalid map line");
	}
}

void	get_map_info(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	line = skip_texture_lines(fd);
	while (1)
	{
		temp = line;
		line = ft_strtrim(line, "\n");
		free(temp);
		check_line(line, game, fd);
		free(line);
		game->input.row_count++;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
}
