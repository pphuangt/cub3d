#include "cub3d.h"

void	color(int32_t color)
{
	draw_color(NULL, &color, NULL);
}

void	border(int32_t color)
{
	draw_color(NULL, NULL, &color);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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
