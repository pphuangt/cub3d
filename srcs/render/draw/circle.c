/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:05:04 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:05 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "cub3d.h"

static void	draw(t_renderer *renderer, t_circle *circle);

void	circle(uint32_t x, uint32_t y, uint32_t r)
{
	t_circle	circle;

	circle.x = x;
	circle.y = y;
	circle.r = r;
	draw_circle(NULL, &circle);
}

void	draw_circle(t_renderer *renderer, t_circle *circle)
{
	static t_renderer	*static_renderer = NULL;

	if (!static_renderer)
	{
		static_renderer = renderer;
		return ;
	}
	draw(static_renderer, circle);
}

static void	draw(t_renderer *renderer, t_circle *circle)
{
	uint32_t	x;
	uint32_t	y;

	y = circle->y - circle->r;
	while (y <= circle->y + circle->r)
	{
		x = circle->x - circle->r;
		while (x <= circle->x + circle->r)
		{
			if ((x - circle->x) * (x - circle->x)
				+ (y - circle->y) * (y - circle->y)
				<= (circle->r * circle->r))
			{
				mlx_put_pixel(renderer->img,
					x,
					y,
					renderer->color);
			}
			x++;
		}
		y++;
	}
}
