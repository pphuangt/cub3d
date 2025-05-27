/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:05:18 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:20 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(t_renderer *renderer, t_rect *rect);

void	rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	t_rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	draw_rect(NULL, &rect);
}

void	draw_rect(t_renderer *renderer, t_rect *rect)
{
	static t_renderer	*static_renderer = NULL;

	if (!static_renderer)
	{
		static_renderer = renderer;
		return ;
	}
	draw(static_renderer, rect);
}

static void	draw(t_renderer *renderer, t_rect *rect)
{
	uint32_t	x;
	uint32_t	y;
	int32_t		color;

	y = 0;
	while (y < rect->h)
	{
		x = 0;
		while (x < rect->w)
		{
			if (y == 0 || y == rect->h - 1 || x == 0 || x == rect->w - 1)
				color = renderer->border;
			else
				color = renderer->color;
			mlx_put_pixel(
				renderer->img,
				x + rect->x,
				y + rect->y,
				color);
			x++;
		}
		y++;
	}
}
