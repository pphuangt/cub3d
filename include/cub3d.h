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
# include "draw.h"
# include "constants.h"

# define TITLE "cub3d"
# define BPP sizeof(uint32_t)

typedef enum s_keys
{
	ESCAPE = 0xFF1B,
}	t_keys;

typedef struct s_graphic
{
	mlx_t		*window;
	mlx_image_t	*img;
	int32_t		width;
	int32_t		height;
}	t_graphic;

typedef struct s_game
{
	t_graphic	graphic;
	t_renderer	renderer;
}	t_game;

void	setup_map(t_game *game);
void	setup_player(t_game *game);
void	setup_graphic(t_game *game);
void	setup_hook(t_game *game);

void	render_map(t_game *game);
void	render_player(t_game *game);

void	ft_error(t_game *game);

void	terminate(t_game *game);

#endif
