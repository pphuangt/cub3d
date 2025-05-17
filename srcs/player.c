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

void	circle(mlx_image_t *img, uint32_t center_x, uint32_t center_y)
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

void	line(mlx_image_t *img, uint32_t start_x, uint32_t start_y, uint32_t end_x, uint32_t end_y)
{
	int	dx = abs((int)end_x - (int)start_x);
    int	dy = -abs((int)end_y - (int)start_y);
    int	sx = start_x < end_x ? 1 : -1;
    int	sy = start_y < end_y ? 1 : -1;
    int	err = dx + dy;
    int	e2;
    
    while (1)
    {
        mlx_put_pixel(img, start_x, start_y, YELLOW);
        if (start_x == end_x && start_y == end_y)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            if (start_x == end_x)
                break;
            err += dy;
            start_x += sx;
        }
        if (e2 <= dx)
        {
            if (start_y == end_y)
                break;
            err += dx;
            start_y += sy;
        }
    }
}

void	draw_player(mlx_image_t *img)
{
	circle(img,
		POSX * TILEX - (TILEX / 2),
		POSY * TILEY - (TILEY / 2));
	line(img,
		POSX * TILEX - (TILEX / 2),
		POSY * TILEY - (TILEY / 2),
		POSX * TILEX - (TILEX / 2),
		ROW * TILEX);
}

void	render_player(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	draw_player(graphic->img);
}
