/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:05:07 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:08 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "cub3d.h"

void	color(int32_t color)
{
	draw_color(NULL, &color, NULL);
}

void	border(int32_t color)
{
	draw_color(NULL, NULL, &color);
}

void	draw_color(t_renderer *renderer, int32_t *color, int32_t *border)
{
	static t_renderer	*static_renderer = NULL;

	if (!static_renderer)
	{
		static_renderer = renderer;
		return ;
	}
	if (color != NULL)
		static_renderer->color = *color;
	if (border != NULL)
		static_renderer->border = *border;
}
