/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 17:48:26 by jcongolo          #+#    #+#             */
/*   Updated: 2024-11-22 17:48:26 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // Para as funções de leitura e escrita
# include <stdlib.h> // Para as funções de alocação de memória
# include <stdio.h> // Para as funções de entrada e saída padrão (usada principalmente em testes)
# include <fcntl.h> // Para declarar open e as constantes de modos de abertura

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1024 // Define o tamanho do buffer para leitura
# endif

/*
 Função: ft_strchr
 Propósito: Encontra a primeira ocorrência do caractere c na string s.
 Uso: Esta função é usada para localizar o caractere de nova linha '\n' em `remainder` na função `ft_extract_line`.
*/
char    *ft_strchr(const char *s, int c);

/*
 Função: ft_strlen
 Propósito: Retorna o comprimento da string s.
 Uso: Esta função é usada para calcular o tamanho de strings para operações de cópia e junção.
*/
size_t  ft_strlen(const char *s);

/*
 Função: ft_strlcpy
 Propósito: Copia até size - 1 caracteres de src para dst, adicionando um terminador nulo.
 Uso: Esta função é usada para copiar strings de forma segura, garantindo que o buffer de 
 destino não seja excedido.
*/
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

/*
 Função: ft_strdup
 Propósito: Duplica a string s.
 Uso: Esta função é usada para criar uma cópia dinâmica de uma string.
*/
char    *ft_strdup(const char *s);

/*
 Função: ft_extract_line
 Propósito: Extrai a próxima linha do remainder.
 Uso: Esta função é usada para obter uma linha completa de texto armazenado em remainder.
*/
char    *ft_extract_line(char **remainder);

/*
 Função: ft_read_and_update_remainder
 Propósito: Lê dados do arquivo e atualiza o conteúdo de remainder.
 Uso: Esta função é usada para ler novos dados do arquivo e adicioná-los ao conteúdo existente 
 em remainder.
*/
int     ft_read_and_update_remainder(int fd, char **remainder);

/*
 Função: get_next_line
 Propósito: Obtém a próxima linha do arquivo.
 Uso: Esta é a função principal que chama `ft_read_and_update_remainder` para ler dados e 
 `ft_extract_line` para extrair a próxima linha.
*/
char    *get_next_line(int fd);

#endif
