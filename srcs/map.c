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
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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

void	draw_map(mlx_image_t *img)
{
	uint32_t	row;
	uint32_t	col;

	memset(img->pixels, 255, img->width * img->height * sizeof(uint32_t));
	row = 0;
	while (row < img->height)
	{
		col = 0;
		while (col < img->width)
		{
			if (wall[row / TILEY][col / TILEX] != 0)
				mlx_put_pixel(img, col, row, 120);
			col++;
		}
		row++;
	}
}

void	render_map(t_game *game)
{
	t_graphic	*graphic;
	mlx_image_t	*img;

	graphic = &game->graphic;
	img = mlx_new_image(graphic->window, graphic->width, graphic->height);
	if (img == NULL)
		ft_error(game);
	draw_map(img);
	if (mlx_image_to_window(graphic->window, img, 0, 0) == -1)
		ft_error(game);
}
