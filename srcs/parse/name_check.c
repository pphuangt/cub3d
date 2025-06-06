/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hg <hg@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 10:47:17 by hg                #+#    #+#             */
/*   Updated: 2025-06-05 10:47:17 by hg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_filename_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] == '.'
		&& filename[len - 3] == 'c'
		&& filename[len - 2] == 'u'
		&& filename[len - 1] == 'b')
		return (0);
	return (-1);
}

void	check_map_filename(char *filename)
{
	if (check_filename_cub(filename) != 0)
	{
		ft_printf(stderr, "Error: Invalid filename (has to end with .cub)\n");
		exit(EXIT_FAILURE);
	}
}

int	check_texture_filename(char **splitted_text_path)
{
	int	len;

	len = ft_strlen(splitted_text_path[1]);
	if (len < 4 || ft_strncmp(splitted_text_path[1] + len - 4, ".xpm", 4) != 0)
		return (1);
}
