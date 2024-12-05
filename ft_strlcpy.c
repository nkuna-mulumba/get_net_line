/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:46:05 by jcongolo          #+#    #+#             */
/*   Updated: 2024/11/26 17:45:34 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	size_t		i;

	src_start = src;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (*src && i < size - 1)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	if (i < size)
	{
		*dst = '\0';
	}
	return (ft_strlen(src_start));
}
