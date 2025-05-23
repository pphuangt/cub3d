#include "cub3d.h"

static void	draw(mlx_image_t *img, t_circle *circle);

void	circle(uint32_t x, uint32_t y, uint32_t r)
{
	t_circle	circle;

	circle.x = x;
	circle.y = y;
	circle.r = r;
	draw_circle(NULL, &circle);
}

void	draw_circle(mlx_image_t *img, t_circle *circle)
{
	static mlx_image_t	*static_img = NULL;

	if (!static_img)
		static_img = img;
	draw(static_img, circle);
}

static void	draw(mlx_image_t *img, t_circle *circle)
{
	(void)img;
	(void)circle;
}
