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
	(void)renderer;
	(void)rect;
}
