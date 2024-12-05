/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:27:07 by jcongolo          #+#    #+#             */
/*   Updated: 2024/12/03 15:28:44 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char	*buffer;
	char	*line;
	char	*newline_pos;
	ssize_t	bytes_read;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	
	printf("Iniciando leitura...\n"); //Rastrear

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		printf("Bytes lidos: %zd\n", bytes_read); //Rastrear
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		free(remainder);
		remainder = temp;

		newline_pos = ft_strchr(remainder, '\n');
		if (newline_pos)
			break;
	}
	free(buffer);
	if (bytes_read < 0 || (!remainder || !*remainder))
		return (NULL);	
	line = ft_extract_line(&remainder);
	printf("Linha extraída: %s\n", line);//Rastrear
	return (line);	
}
