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
# include <math.h>
# include "constants.h"
# include "fcntl.h"

# define TITLE "cub3d"
# define TEXTURE_COUNT 5 //NO, SO, WE, EA, D

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
	t_input		input;
	int			**map_data;

}	t_game;

typedef struct s_input
{
	t_graphic	*textures;
	char		*map;
	int			row_count;
	int			col_count;
	int			posx;
	int			posy;
	char		pos_dirctn;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*door_path;
	char		*f_color;
	char		*c_color;
	int			f_color_int;
	int			c_color_int;
}	t_input;

void	parse_map_file(char *in_file, t_game *game);
void    setup_map(t_game *game);
void    render_map(t_game *game);
void    setup_player(t_game *game);
void    render_player(t_game *game);

void	check_map_filename(char *filename);
void	allocate_texture(t_game *game);
int		parse_texture(char *filename, t_game *game);
int		check_texture_filename(char **splitted_text_path);
int		parse_color_str(char *filename, t_game *game);
void	get_map_info(char *filename, t_game *game);
void	load_and_validate_map(char *filename, t_game *game);
void    check_map(t_game *game);
void	check_udr(t_game *game, int x, int y);
void	check_udl(t_game *game, int x, int y);
void	check_dlr(t_game *game, int x, int y);
void	check_ulr(t_game *game, int x, int y);
void	check_udlr(t_game *game, int x, int y);

void	check_malloc(void *ptr, t_game *game);
void	free_and_exit(t_game *game, const char *msg);
char	*skip_texture_lines(int fd, t_game *game);


void	esc_exit(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);

void	ft_error(t_game *game);

void	game_terminate(t_game *game);

#endif
