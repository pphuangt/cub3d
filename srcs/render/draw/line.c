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

#include "draw.h"
#include "cub3d.h"

static void	draw(t_renderer *renderer, t_line *line);
static void	put_pixel(t_renderer *renderer, int32_t x, int32_t y);

void	line(int x1, int y1, int x2, int y2)
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
	int		steps;
	double	x_increment;
	double	y_increment;
	double	current_x;
	double	current_y;

	x_increment = line->x2 - line->x1;
	y_increment = line->y2 - line->y1;
	if (fabs(x_increment) > fabs(y_increment))
		steps = fabs(x_increment);
	else
		steps = fabs(y_increment);
	x_increment = x_increment / (double)steps;
	y_increment = y_increment / (double)steps;
	current_x = line->x1;
	current_y = line->y1;
	while (steps--)
	{
		put_pixel(renderer, round(current_x), round(current_y));
		current_x += x_increment;
		current_y += y_increment;
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
