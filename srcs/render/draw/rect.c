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

#include "draw.h"
#include "cub3d.h"

static void	draw(t_renderer *renderer, t_rect *rect);

void	rect(int x, int y, int w, int h)
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
	int		i;
	int		j;

	i = rect->x;
	while (i < (rect->x + rect->w))
	{
		j = rect->y;
		while (j < (rect->y + rect->h))
		{
			if (i == rect->x || i == (rect->x + rect->w - 1)
				|| j == rect->y || j == (rect->y + rect->h - 1))
				mlx_put_pixel(renderer->img, i, j, renderer->border);
			else
				mlx_put_pixel(renderer->img, i, j, renderer->color);
			j++;
		}
		i++;
	}
}
