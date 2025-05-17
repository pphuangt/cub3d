/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:09:44 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/17 11:09:46 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_player(t_game	*game)
{
	(void) game;
}

/*
void	draw_player(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	ex;
	uint32_t	ey;
	double		center;

	y = POSY * TILEY - TILEY / 2 - RADIUS;
	ex = POSX * TILEX - TILEX / 2 + RADIUS;
	ey = POSY * TILEY - TILEY / 2 + RADIUS;
	center = RADIUS - 0.5f;
	while (y < ey)
	{
		x = POSX * TILEX - TILEX / 2 - RADIUS;
		while (x < ex)
		{
			if ((x - center) * (x - center) + (y - center) * (y - center)
				<= (RADIUS * RADIUS))
				mlx_put_pixel(img, x, y, RED);
			x++;
		}
		y++;
	}
}
*/

void	draw_player(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	start_x;
	uint32_t	start_y;
	uint32_t	end_x;
	uint32_t	end_y;
	uint32_t	center_x;
	uint32_t	center_y;

	center_x = POSX * TILEX - (TILEX / 2);
	center_y = POSY * TILEY - (TILEY / 2);
	start_x = center_x - RADIUS;
	start_y = center_y - RADIUS;
	end_x = center_x + RADIUS;
	end_y = center_y + RADIUS;
	y = start_y;
	while (y <= end_y)
	{
		x = start_x;
		while (x <= end_x)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= (RADIUS * RADIUS))
				mlx_put_pixel(img, x, y, RED);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	draw_player(graphic->img);
}
