/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 05:49:33 by hg                #+#    #+#             */
/*   Updated: 2025-06-03 05:49:33 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_color_str(char F_or_C, char *line, t_game *game)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp || !tmp[0])
		free_and_exit(game, "Invalid color line");
	if (F_or_C == 'F')
	{
		game->input.f_color = ft_strdup(tmp[1]);
		if (!game->input.f_color)
			free_and_exit(game, "Floor color failed");
		game->input.f_color[ft_strlen(tmp[1]) - 1] = 0;
	}
	else if (F_or_C == 'C')
	{
		game->input.c_color = ft_strdup(tmp[1]);
		if (!game->input.c_color)
			free_and_exit(game, "Ceiling color failed");
		game->input.c_color[ft_strlen(tmp[1]) - 1] = 0;
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

int	parse_color_str(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "F", 1) == 0)
			get_color_str('F', line, game);
		else if (ft_strncmp(line, "C", 1) == 0)
			get_color_str('C', line, game);
		free(line);
	}
	close(fd);
	return (0);
}
