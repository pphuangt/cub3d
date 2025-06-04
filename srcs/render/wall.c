/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:47:07 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/03 08:47:09 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				render_ceil_floor(int width, int height);
static void				render_projection_wall(t_game *game, int width, int height);
static void				draw_wall_texture(t_game *game, double wall_height, int i);
static mlx_texture_t	*get_texture(t_ray *ray, mlx_texture_t *textures[4]);

void	render_wall(t_game *game)
{
	t_map	*map;

	map = &game->map;
	render_ceil_floor(map->width, map->height);
	render_projection_wall(game, map->width, map->height);
}

static void	render_ceil_floor(int width, int height)
{
	border(BLUE);
	color(BLUE);
	rect(0, 0, width, height / 2);
	border(GREY);
	color(GREY);
	rect(0, height / 2, width, height / 2);
}

static void	render_projection_wall(t_game *game, int width, int height)
{
	double	wall_height;
	double	correct_distance;
	int		i;

	i = 0;
	while (i < width)
	{
		correct_distance = game->rays[i].distance
			* cos(game->player.rotation_angle - game->rays[i].angle);
		wall_height = (TILE_SIZE / correct_distance) * game->dist_proj_plane;
		if (wall_height > height)
			wall_height = height;
		draw_wall_texture(game, wall_height, i);
		i++;
	}
}

static void draw_wall_texture(t_game *game, double wall_height, int i)
{
    int             texture_offset_x;
    int             texture_offset_y;
    int             wall_top_y;
    int             wall_bottom_y;
    mlx_texture_t   *texture;

    texture = get_texture(&game->rays[i], game->map.textures);
    if (game->rays[i].was_hit_vertical)
        texture_offset_x = (int)game->rays[i].y % TILE_SIZE;
    else
        texture_offset_x = (int)game->rays[i].x % TILE_SIZE;

    wall_top_y = (game->map.height / 2) - (wall_height / 2);
    if (wall_top_y < 0)
        wall_top_y = 0;
    wall_bottom_y = (game->map.height / 2) + (wall_height / 2);
    if (wall_bottom_y > game->map.height)
        wall_bottom_y = game->map.height;

    for (int y = wall_top_y; y < wall_bottom_y; y++) {
        int distance_from_top = y + (wall_height / 2) - (game->map.height / 2);
        texture_offset_y = distance_from_top * ((float)texture->height / wall_height);

        // Clamp texture coordinates
        if (texture_offset_x >= (int)texture->width) texture_offset_x = texture->width - 1;
        if (texture_offset_y >= (int)texture->height) texture_offset_y = texture->height - 1;
        if (texture_offset_x < 0) texture_offset_x = 0;
        if (texture_offset_y < 0) texture_offset_y = 0;


    	// อ่าน pixel แยกเป็น RGBA components
    	uint32_t pixel_index = (texture_offset_y * texture->width + texture_offset_x) * 4;
    	uint8_t r = texture->pixels[pixel_index];
    	uint8_t g = texture->pixels[pixel_index + 1];
    	uint8_t b = texture->pixels[pixel_index + 2];
    	uint8_t a = texture->pixels[pixel_index + 3];

    	// ใช้ ft_pixel function ที่มีอยู่
    	int32_t color = ft_pixel(r, g, b, a);

    	mlx_put_pixel(game->graphic.img, i, y, color);
    }
}

static mlx_texture_t	*get_texture(t_ray *ray, mlx_texture_t *textures[4])
{
	if (ray->was_hit_vertical)
	{
		if (ray_facing_left(ray->angle))
			return (textures[0]);
		else
			return (textures[1]);
	}
	else
	{
		if (ray_facing_up(ray->angle))
			return (textures[2]);
		else
			return (textures[3]);
	}
}