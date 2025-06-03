/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:47:07 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/03 08:47:09 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_wall(t_game *game)
{
	t_map	*map;

	map = &game->map;
	border(BLUE);
	color(BLUE);
	rect(0, 0, map->width, map->height / 2);
	border(GREY);
	color(GREY);
	rect(0, map->height / 2, map->width, map->height / 2);
}
