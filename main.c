/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:54:18 by jarrakis          #+#    #+#             */
/*   Updated: 2022/01/25 21:28:30 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *link_map)
{
	if (!ft_strnstr(link_map, ".ber", 50))
		return (1);
	printf("%s\n", link_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("error argument!\n");
	}
	if (read_map(argv[1]))
		printf("error map format\n");
}
