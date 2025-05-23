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

static void	draw_player(mlx_image_t *img);
static void	circle(mlx_image_t *img, uint32_t center_x, uint32_t center_y);

void	setup_player(t_game	*game)
{
	(void) game;
}

void	render_player(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	draw_player(graphic->img[0]);
}

static void	draw_player(mlx_image_t *img)
{
	circle(img,
		POSX * TILEX - (TILEX / 2),
		POSY * TILEY - (TILEY / 2));
}

static void	circle(mlx_image_t *img, uint32_t center_x, uint32_t center_y)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	radius_squared;

	radius_squared = RADIUS * RADIUS;
	y = center_y - RADIUS;
	while (y <= center_y + RADIUS)
	{
		x = center_x - RADIUS;
		while (x <= center_x + RADIUS)
		{
			if ((x - center_x) * (x - center_x)
				+ (y - center_y) * (y - center_y)
				<= radius_squared)
				mlx_put_pixel(img, x, y, RED);
			x++;
		}
		y++;
	}
}
