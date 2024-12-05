/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 17:57:31 by jcongolo          #+#    #+#             */
/*   Updated: 2024/11/27 17:26:33 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	length_s1;
	size_t	length_s2;
	char	*new_s;

	if (!(s1 || s2))
	{
		return (NULL);
	}
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	new_s = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (!new_s)
	{
		return (NULL);
	}
	ft_strlcpy(new_s, s1, length_s1 + 1);
	ft_strlcat(new_s, s2, length_s1 + length_s2 + 1);
	return (new_s);
}
