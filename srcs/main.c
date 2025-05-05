/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:29:50 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/05 13:29:52 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_hook(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_loop_end(mlx->ptr);
	return (0);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
		exit_hook(mlx);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	int		errsv;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		error_exit("mlx init", errno);
	mlx.win = mlx_new_window(mlx.ptr, 400, 400, "cub3d");
	if (!mlx.win)
	{
		errsv = errno;
		mlx_destroy_display(mlx.ptr);
		error_exit("mlx new window", errsv);
	}
	mlx_hook(mlx.win, DestroyNotify,
		Button1MotionMask, exit_hook, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, key_hook, &mlx);
	mlx_loop(mlx.ptr);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
	return (0);
}
