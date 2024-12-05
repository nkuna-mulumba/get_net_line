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

NAME = get_next_line
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

all : $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
