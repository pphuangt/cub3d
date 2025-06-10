/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:45:53 by pphuangt          #+#    #+#             */
/*   Updated: 2025/06/10 11:08:00 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define DS 100
# define DB 2

# define BS BUFFER_SIZE

typedef struct s_gnl_list
{
	char		*str;
	ssize_t		length;
	ssize_t		size;
}	t_gnl_list;

char	*get_next_line(int fd);
void	free_t_list(t_gnl_list **src);
void	*ft_gnl_memmove(void *dst, const void *src, size_t len);

#endif
