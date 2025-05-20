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

void	parse_map_file(char *in_file, t_game *game)
{
	int fd;
	(void)game;

	fd = open(in_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	
}