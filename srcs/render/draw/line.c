#include "cub3d.h"

static void	draw(t_renderer *renderer, t_line *line);

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

	if (!renderer)
	{
		static_renderer = renderer;
		return ;
	}
	draw(static_renderer, line);
}

static void	draw(t_renderer *renderer, t_line *line)
{
	(void)renderer;
	(void)line;
}
