# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/01/22 21:54:22 by jarrakis          #+#    #+#             #
#   Updated: 2022/01/22 21:54:22 by jarrakis         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = so_long
CC = gcc

main:
	$(CC) main.c so_long_utils.c so_long_utils_1.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c -lmlx -framework OpenGL -framework AppKit -o $(NAME)

tmap:	main
	./$(NAME) maps/test_map.ber