/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcongolo <jcongolo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 17:48:48 by jcongolo          #+#    #+#             */
/*   Updated: 2024-11-22 17:48:48 by jcongolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# Nome do executável final
NAME = get_next_line

# Arquivos fonte do projeto
SRC = get_next_line.c

# Objetos compilados a partir dos arquivos fonte
OBJ = $(SRC:.c=.o)

# Flags do compilador para mostrar todos os avisos, tratar avisos como erros e mostrar avisos extras
FLAGS = -Wall -Werror -Wextra

# Compilador a ser usado
CC = cc

# Regra padrão para compilar o executável
all : $(NAME)

# Regras para criar o executável a partir dos objetos
$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

# Regra para limpar os arquivos objeto
clean: 
	rm -f $(OBJ)

# Regra para limpar todos os arquivos gerados, incluindo o executável
fclean: clean
	rm -f $(NAME)

# Regra para reconstruir tudo do zero
re: fclean all
