/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:05:15 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:16 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(t_renderer *renderer, t_line *line);
static void	put_pixel(t_renderer *renderer, int32_t x, int32_t y);

void	line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	t_line	line;

	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	draw_line(NULL, &line);
}

void	draw_line(t_renderer *renderer, t_line *line)
{
	static t_renderer	*static_renderer = NULL;

	if (!static_renderer)
	{
		static_renderer = renderer;
		return ;
	}
	draw(static_renderer, line);
}

static void	draw(t_renderer *renderer, t_line *line)
{
	int32_t	dx;
	int32_t	dy;
	int32_t	steps;
	int32_t	x;
	int32_t	y;

	dx = line->x2 - line->x1;
	dy = line->y2 - line->y1;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x = line->x1 * 1000;
	y = line->y1 * 1000;
	dx = (dx * 1000) / steps;
	dy = (dy * 1000) / steps;
	while (steps >= 0)
	{
		put_pixel(renderer, x / 1000, y / 1000);
		x += dx;
		y += dy;
		steps--;
	}
}

static void	put_pixel(t_renderer *renderer, int32_t x, int32_t y)
{
	if (x >= 0 && x < (int32_t)renderer->img->width
		&& y >= 0 && y < (int32_t)renderer->img->height)
	{
		mlx_put_pixel(renderer->img, x, y, renderer->color);
	}
}
