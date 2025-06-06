/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-04 16:21:52 by hg                #+#    #+#             */
/*   Updated: 2025-06-04 16:21:52 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_malloc(void *ptr, t_game *game)
{
	if (!ptr)
		free_and_exit(game, "Error allocating memory");
}

void	free_input_memory(t_game *game)
{
	if (game->input.textures)
		free(game->input.textures);
	if (game->input.map)
		free(game->input.map);
	if (game->input.no_path)
		free(game->input.no_path);
	if (game->input.so_path)
		free(game->input.so_path);
	if (game->input.we_path)
		free(game->input.we_path);
	if (game->input.ea_path)
		free(game->input.ea_path);
	if (game->input.f_color)
		free(game->input.f_color);
	if (game->input.c_color)
		free(game->input.c_color);
}

void	free_and_exit(t_game *game, const char *msg)
{
	int	status;

	status = EXIT_SUCCESS;
	if (msg)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		perror(msg);
		status = EXIT_FAILURE;
	}
	free_input_memory(game);
	exit(status);
}

char	*skip_texture_lines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "NO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
			|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0
			|| ft_strncmp(line, "\n", 1) == 0)
		{
			free(line);
			continue ;
		}
		break ;
	}
	return (line);
}
