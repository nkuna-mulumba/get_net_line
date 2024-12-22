/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:27:07 by jcongolo          #+#    #+#             */
/*   Updated: 2024/12/09 16:07:10 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 Função: ft_strlcat
 Propósito: Concatena src no final de dst, garantindo que o resultado seja null-terminado.
 Uso: Esta função é usada para concatenar strings sem exceder o tamanho do buffer de destino.
*/
static size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_dst;
	size_t	length_src;
	int		i;

	length_dst = ft_strlen(dst); // Obtém o comprimento de dst
	length_src = ft_strlen(src); // Obtém o comprimento de src
	i = 0;

	if (length_dst >= size)
	{
		return (size + length_src); // Retorna o comprimento combinado se o tamanho do buffer for excedido
	}

	while (src[i] && (length_dst + i) < (size - 1))
	{
		dst[length_dst + i] = src[i]; // Concatena src a dst
		i++;
	}
	dst[length_dst + i] = '\0'; // Adiciona o terminador nulo

	return (length_dst + length_src); // Retorna o comprimento total
}

/*
 Função: ft_strjoin
 Propósito: Junta duas strings em uma nova string.
 Uso: Esta função é usada para combinar o conteúdo de `remainder` com o buffer lido do arquivo.
*/
static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_s;
	size_t	length_s1;
	size_t	length_s2;

	if (!s1 && !s2)
		return (NULL); // Se ambas as strings forem NULL, retorna NULL
	if (!s1)
		return (ft_strdup(s2)); // Se s1 for NULL, duplica s2
	if (!s2)
		return (ft_strdup(s1)); // Se s2 for NULL, duplica s1
	
	length_s1 = ft_strlen(s1); // Obtém o comprimento de s1
	length_s2 = ft_strlen(s2); // Obtém o comprimento de s2
	new_s = (char *)malloc((length_s1 + length_s2 + 1) * sizeof(char)); // Obtém o comprimento de s2
	if (!new_s)
		return (NULL); // Retorna NULL se a alocação falhar
	
	ft_strlcpy(new_s, s1, length_s1 + 1); // Copia s1 para new_s
	ft_strlcat(new_s, s2, length_s1 + length_s2 + 1); // Concatena s2 a new_s
	
	return (new_s); // Retorna a nova string
}
/*
Função: ft_read_and_update_remainder
Propósito: Lê dados do arquivo e atualiza o conteúdo de remainder até encontrar uma nova linha.
Uso: Esta função é usada para ler novos dados do arquivo e adicioná-los ao conteúdo existente em remainder, até que uma nova linha seja encontrada.
*/
int ft_read_and_update_remainder(int fd, char **remainder)
{
    char    *buffer;
    char    *temp;
    ssize_t bytes_read;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // Aloca memória para o buffer
    if (!buffer)
        return (-1); // Retorna -1 se a alocação falhar
    bytes_read = 1; // Inicializa bytes_read com 1 para entrar no loop
    while (bytes_read && !ft_strchr(*remainder, '\n')) // Continua lendo até encontrar uma nova linha
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE); // Lê do arquivo para o buffer
        if (bytes_read <= 0)
        {
            free(buffer); // Libera o buffer se a leitura falhar ou chegar ao fim do arquivo
            return (bytes_read); // Retorna o número de bytes lidos (ou erro)
        }
        buffer[bytes_read] = '\0'; // Adiciona o terminador nulo ao buffer
        temp = ft_strjoin(*remainder, buffer); // Junta remainder e buffer
        if (!temp)
            return (-1); // Retorna -1 se a junção falhar
        free(*remainder); // Libera o antigo remainder
        *remainder = temp; // Atualiza remainder para a nova string combinada
    }
    free(buffer); // Libera o buffer após sair do loop
    return (bytes_read); // Retorna o número de bytes lidos
}
/*
 Função: get_next_line
 Propósito: Obtém a próxima linha do arquivo.
 Uso: Esta função é a função principal que chama `ft_read_and_update_remainder` para ler 
 dados e `ft_extract_line` para extrair a próxima linha.
*/
char	*get_next_line(int fd)
{
	static char	*remainder; // Variável estática para armazenar os dados restantes
	char		*line;
	int			result; // Variável para armazenar o resultado da operação de leitura

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL); // Retorna NULL para descritor de arquivo inválido ou tamanho de buffer inválido
	
	result = ft_read_and_update_remainder(fd, &remainder); // Lê e atualiza remainder

	if ((result <= 0) && (!remainder || *remainder == '\0'))
	{
		free(remainder); // Libera remainder se o fim do arquivo for alcançado
		remainder = NULL;
		return (NULL); // Retorna NULL no final do arquivo
	}
	
	line = ft_extract_line(&remainder); // Extrai a linha do remainder
	return (line); // Retorna a linha extraída }
}
