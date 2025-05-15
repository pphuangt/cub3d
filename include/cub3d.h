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
# include "MLX42/MLX42.h"
# include "libft.h"

# define WINDOW_WIDTH 512
# define WINDOW_HEIGHT 512
# define TITLE "cub3d"

typedef enum s_keys
{
	ESCAPE = 0xFF1B,
}	t_keys;

typedef struct s_graphic
{
	mlx_t		*window;
}	t_graphic;

typedef struct s_map
{
	mlx_image_t	*img;
	int			row;
	int			col;
	int			tile_x;
	int			tile_y;
	int			wall[100][100];
}	t_map;

typedef struct s_game
{
	t_graphic	graphic;
	t_map		map;
}	t_game;

void	set_map(t_game *game);
void	render_map(t_game *game);

void	esc_exit(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);

void	ft_error(t_game *game);

void	game_terminate(t_game *game);

#endif
