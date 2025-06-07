/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:26:40 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/30 20:26:42 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ray_facing_down(double angle)
{
	return (angle > 0 && angle < PI);
}

bool	ray_facing_up(double angle)
{
	return (!ray_facing_down(angle));
}

bool	ray_facing_right(double angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

bool	ray_facing_left(double angle)
{
	return (!ray_facing_right(angle));
}

int	ray_texture_id(double angle, bool is_vertical_hit)
{
	if (!is_vertical_hit)
	{
		if (ray_facing_up(angle))
			return (SOUTH);
		return (NORTH);
	}
		if (ray_facing_left(angle))
			return (EAST);
		return (WEST);
}
