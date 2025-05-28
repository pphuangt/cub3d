/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:05:11 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:12 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "cub3d.h"

void	setup_draw(t_game *game)
{
	t_graphic			*graphic;
	static t_renderer	renderer;

	graphic = &game->graphic;
	renderer.img = graphic->img;
	renderer.border = 0;
	renderer.color = 0;
	draw_rect(&renderer, NULL);
	draw_line(&renderer, NULL);
	draw_circle(&renderer, NULL);
	draw_color(&renderer, NULL, NULL);
}
