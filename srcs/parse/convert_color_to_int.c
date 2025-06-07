/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_to_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:35:28 by plesukja          #+#    #+#             */
/*   Updated: 2025/06/07 14:35:35 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_rgb_format(char *color_str, t_game *game)
{
	int		i;
	int		digits;
	int		color;

	if (!color_str)
		free_and_exit(game, "No color found.");
	i = 0;
	color = 0;
	while (color < 3)
	{
		digits = 0;
		while (ft_isdigit(color_str[i]))
		{
			i++;
			digits++;
		}
		if ((digits == 0 || digits > 3)
			|| (color_str[i] != ',' && color < 2)
			|| (color_str[i] != '\0' && color == 2))
			return (1);
		i++;
		color++;
	}
	return (0);
}

static int	check_rgb_value(char *color_str, t_game *game)
{
	char	**tmp;
	int		i;
	int		value;

	tmp = ft_split(color_str, ',');
	if (!tmp || !tmp[0] || !tmp[1] || !tmp[2])
		free_and_exit(game, "Error splitting color string.");
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(tmp[i]);
		if (value < 0 || value > 255)
		{
			while (i < 3)
				free(tmp[i++]);
			free(tmp);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 3)
		free(tmp[i++]);
	free(tmp);
	return (0);
}

static int	check_rgb_format_and_value(char *color_str, t_game *game)
{
	if (check_rgb_format(color_str, game))
		return (1);
	if (check_rgb_value(color_str, game))
		return (1);
	return (0);
}

static int32_t	convert_color(char **c)
{
	int32_t	tmp;

	tmp = ft_pixel(ft_atoi(c[0]), ft_atoi(c[1]), ft_atoi(c[2]), 255);
	free(c[0]);
	free(c[1]);
	free(c[2]);
	free(c);
	return (tmp);
}

void	convert_colors(t_game *game)
{
	char	**tmp;

	if (check_rgb_format_and_value(game->input.f_color, game))
		free_and_exit(game, "Invalid color format or value in f_color");
	if (check_rgb_format_and_value(game->input.c_color, game))
		free_and_exit(game, "Invalid color format or value in c_color");
	tmp = ft_split(game->input.f_color, ',');
	if (!tmp)
		free_and_exit(game, "Error splitting f_color string.");
	game->input.f_color_int = convert_color(tmp);
	tmp = ft_split(game->input.c_color, ',');
	if (!tmp)
		free_and_exit(game, "Error splitting c_color string.");
	game->input.c_color_int = convert_color(tmp);
}
