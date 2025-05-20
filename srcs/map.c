/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:09:40 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/17 11:09:41 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall[ROW][COL] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	setup_map(t_game *game)
{
	t_graphic	*graphic;

	graphic = &game->graphic;
	graphic->height = TILEY * ROW;
	graphic->width = TILEX * COL;
}

//---original draw_map function---
// void	draw_map(mlx_image_t *img)
// {
// 	uint32_t	row;
// 	uint32_t	col;

// 	memset(img->pixels, 255, img->width * img->height * sizeof(uint32_t));
// 	row = 0;
// 	while (row < img->height)
// 	{
// 		col = 0;
// 		while (col < img->width)
// 		{
// 			if (wall[row / TILEY][col / TILEX] != 0)
// 				mlx_put_pixel(img, col, row, GREY);
// 			col++;
// 		}
// 		row++;
// 	}
// }

void	draw_map(t_game *game)
{
	uint32_t	row;
	uint32_t	col;

	t_graphic	*graphic = &game->graphic;
	mlx_image_t	*img = graphic->img;
	memset(img->pixels, 255, img->width * img->height * sizeof(uint32_t));
	row = 0;
	while (row < img->height)
	{
		col = 0;
		while (col < img->width)
		{
			if (game->map_data[row / TILEY][col / TILEX] != 0)
				mlx_put_pixel(img, col, row, GREY);
			col++;
		}
		row++;
	}
}

// -- original render_map function ---
// void	render_map(t_game *game)
// {
// 	t_graphic	*graphic;

// 	graphic = &game->graphic;
// 	draw_map(graphic->img);
// }

void	render_map(t_game *game)
{
	draw_map(game);
}
