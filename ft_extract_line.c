/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 14:10:21 by jcongolo          #+#    #+#             */
/*   Updated: 2024/12/02 17:24:41 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s)
{
	size_t	lengt;
	char	*s_dup;

	lengt = ft_strlen(s);
	s_dup = malloc((lengt + 1) * sizeof(char));
	if (!s_dup)
		return (NULL);
	ft_strlcpy(s_dup, s, lengt + 1);
	return (s_dup);
}

char	*ft_extract_line(char **remainder)
{
	char	*newline_pos;
	char	*line;
	size_t	len;
	char	*temp;

	if (!remainder || !*remainder)
		return (NULL);
	newline_pos = ft_strchr(*remainder, '\n');
	if (!newline_pos)
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	len = newline_pos - *remainder + 1;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *remainder, len + 1);
	temp = ft_strdup(newline_pos + 1);
	free(*remainder);
	*remainder = temp;
	return (line);
}