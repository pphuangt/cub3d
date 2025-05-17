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

void	draw_player(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	double		center;

	center = RADIUS - 0.5f;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if ((x - center) * (x - center) + (y - center) * (y - center)
				<= (RADIUS * RADIUS))
				mlx_put_pixel(img, x, y, RED);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	t_graphic	*graphic;
	mlx_image_t	*img;

	graphic = &game->graphic;
	img = mlx_new_image(graphic->window, RADIUS * 2, RADIUS * 2);
	if (img == NULL)
		ft_error(game);
	draw_player(img);
	if (mlx_image_to_window(graphic->window, img, POSX - RADIUS, POSY - RADIUS)
		== -1)
		ft_error(game);
}
