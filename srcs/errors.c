/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuangt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:04:31 by pphuangt          #+#    #+#             */
/*   Updated: 2025/05/05 15:04:33 by pphuangt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message, int code)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	if (code > 0)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(code), STDERR_FILENO);
	}
	exit(1);
}
