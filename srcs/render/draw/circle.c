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
	(void)renderer;
	(void)circle;
}
