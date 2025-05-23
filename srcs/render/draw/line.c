#include "cub3d.h"

static void	draw(mlx_image_t *img, t_line *line);

void	line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	t_line	line;

	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	draw_line(NULL, &line);
}

void	draw_line(mlx_image_t *img, t_line *line)
{
	static mlx_image_t	*static_img = NULL;

	if (!static_img)
		static_img = img;
	draw(static_img, line);
}

static void	draw(mlx_image_t *img, t_line *line)
{
	(void)img;
	(void)line;
}
