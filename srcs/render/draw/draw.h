/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:06:32 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/27 20:06:34 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdlib.h>
# include "MLX42/MLX42.h"

typedef struct s_renderer
{
	mlx_image_t	*img;
	int32_t		border;
	int32_t		color;
}	t_renderer;

typedef struct s_rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_rect;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_line;

typedef struct s_circle
{
	int	x;
	int	y;
	int	r;
}	t_circle;

void	draw_rect(t_renderer *renderer, t_rect *rect);
void	draw_line(t_renderer *renderer, t_line *line);
void	draw_circle(t_renderer *renderer, t_circle *circle);
void	draw_color(t_renderer *renderer, int32_t *color, int32_t *border);

#endif
