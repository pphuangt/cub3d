/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:29:35 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/05 13:29:37 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "constants.h"

# define TITLE "cub3d"
# define MOVE_SPEED 2.0
# define ROTATE_SPEED 0.05

enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_graphic
{
	mlx_t		*window;
	mlx_image_t	*img;
	int32_t		width;
	int32_t		height;
}	t_graphic;

typedef struct s_map
{
	int	**wall;
	int	col;
	int	row;
}	t_map;

typedef struct s_player
{
	uint32_t	x;
	uint32_t	y;
	double		angle;
}	t_player;

typedef struct s_game
{
	t_graphic	graphic;
	t_map		map;
	t_player	player;
}	t_game;

void	setup_map(t_game *game);
void	setup_player(t_game *game);
void	setup_graphic(t_game *game);
void	setup_hook(t_game *game);
void	setup_draw(t_game *game);

void	render_map(t_game *game);
void	render_player(t_game *game);

void	update(t_game *game);
void	update_player(void *param);

bool	has_wall(uint32_t x, uint32_t y);

void	rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
void	line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
void	circle(uint32_t x, uint32_t y, uint32_t r);
void	color(int32_t color);
void	border(int32_t color);

void	ft_error(t_game *game);

void	terminate(t_game *game);

#endif
