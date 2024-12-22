/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-06 22:33:44 by jcongolo          #+#    #+#             */
/*   Updated: 2024/12/09 15:48:15 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 Função: ft_strchr
 Propósito: Encontra a primeira ocorrência do caractere c na string s.
 Uso: Esta função é usada para localizar o caractere de nova linha '\n'
 em `remainder` na função `ft_extract_line`.
*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
	{
		return (NULL);
	}
	while (*s) // Itera através da string s
	{
		if (*s == (unsigned char)c) // Verifica se o caractere atual é c
		{
			return ((char *)s); // Retorna o ponteiro para a posição de c
		}
		s++; // Avança para o próximo caractere na string
	}

	if (*s == (unsigned char)c) // Verifica o caractere nulo no final
	{
		return ((char *)s); // Retorna o ponteiro para a posição de c
	}

	return (NULL); // Retorna NULL se c não for encontrado
}

/* 
 Função: ft_strlen
 Propósito: Retorna o comprimento da string s.
 Uso: Esta função é usada para calcular o tamanho de strings para operações 
 de cópia e junção.
*/
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;

	while (*s != '\0') // Itera até o final da string
	{
		length++; // Incrementa o comprimento
		s++; // Avança para o próximo caractere
	}

	return (length); // Retorna o comprimento total
}

/* 
 Função: ft_strlcpy
 Propósito: Copia até size - 1 caracteres de src para dst, adicionando um terminador nulo.
 Uso: Esta função é usada para copiar strings de forma segura, garantindo que o buffer 
 de destino não seja excedido.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	size_t		i;

	src_start = src; // Mantém o início de src

	if (size == 0)
	{
		return (ft_strlen(src)); // Retorna o comprimento de src se size for 0
	}

	i = 0;

	while (*src && i < size - 1) // Copia até size - 1 caracteres
	{
		*dst = *src; // Copia o caractere de src para dst
		src++; // Avança src
		dst++; // Avança dst
		i++; // Incrementa o contador
	}

	if (i < size)
	{
		*dst = '\0'; // Adiciona o terminador nulo
	}

	return (ft_strlen(src_start)); // Adiciona o terminador nulo
}

/*
 Função: ft_strdup
 Propósito: Duplica a string s.
 Uso: Esta função é usada para criar uma cópia dinâmica de uma string.
*/
char	*ft_strdup(const char *s)
{
	size_t	lengt;
	char	*s_dup;

	lengt = ft_strlen(s); // Calcula o comprimento de s
	s_dup = malloc((lengt + 1) * sizeof(char)); // Aloca memória para a cópia
	if (!s_dup)
		return (NULL); // Retorna NULL se a alocação falhar
	
	ft_strlcpy(s_dup, s, lengt + 1); // Copia s para a memória alocada
	
	return (s_dup); // Retorna a cópia duplicada
}

/* 
 Função: ft_extract_line
 Propósito: Extrai a próxima linha do remainder.
 Uso: Esta função é usada para obter uma linha completa de texto armazenado em remainder.
*/
char	*ft_extract_line(char **remainder)
{
	char	*newline_pos;
	char	*line;
	size_t	len;
	char	*temp;

	if (!remainder || !*remainder)
		return (NULL); // Retorna NULL se remainder for NULL ou vazio

	newline_pos = ft_strchr(*remainder, '\n'); // Procura o caractere de nova linha
	if (!newline_pos)
	{
		line = ft_strdup(*remainder); // Duplica o remainder inteiro se não houver nova linha
		free(*remainder);// Libera a memória de remainder
		*remainder = NULL; // Define remainder como NULL
		return (line); // Retorna a linha duplicada
	}

	len = newline_pos - *remainder + 1; // Calcula o comprimento da linha incluindo \n
	line = malloc((len + 1) * sizeof(char)); // Aloca memória para a linha
	if (!line)
		return (NULL);// Retorna NULL se a alocação falhar
	ft_strlcpy(line, *remainder, len + 1); // Copia a linha para a memória alocada

	temp = ft_strdup(newline_pos + 1); // Duplica o restante após \n
	free(*remainder); // Libera a memória de remainder
	*remainder = temp; // Atualiza remainder para apontar para o restante
	
	return (line); // Retorna a linha extraída
}
