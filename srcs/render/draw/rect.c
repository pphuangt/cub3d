#include "cub3d.h"

static void	draw(mlx_image_t *img, t_rect *rect);

void	rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	t_rect	rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	draw_rect(NULL, &rect);
}

void	draw_rect(mlx_image_t *img, t_rect *rect)
{
	static mlx_image_t	*static_img = NULL;

	if (!static_img)
		static_img = img;
	draw(static_img, rect);
}

static void	draw(mlx_image_t *img, t_rect *rect)
{
	(void)img;
	(void)rect;
}
