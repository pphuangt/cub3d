#ifndef DRAW_H
# define DRAW_H

typedef struct s_game	t_game;

typedef struct s_renderer
{
	mlx_image_t	*img;
	int32_t		border;
	int32_t		color;
}	t_renderer;

typedef struct s_rect
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	w;
	uint32_t	h;
}	t_rect;

typedef struct s_line
{
	uint32_t	x1;
	uint32_t	y1;
	uint32_t	x2;
	uint32_t	y2;
}	t_line;

typedef struct s_circle
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	r;
}	t_circle;

void	setup_draw(t_game *game);
void	draw_rect(t_renderer *renderer, t_rect *rect);
void	draw_line(t_renderer *renderer, t_line *line);
void	draw_circle(t_renderer *renderer, t_circle *circle);
void	draw_color(t_renderer *renderer, int32_t *color, int32_t *border);
void	rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
void	line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
void	circle(uint32_t x, uint32_t y, uint32_t r);
void	color(int32_t color);
void	border(int32_t color);

#endif
