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

int	read_map(char *link_map, t_data *data)
{
	int		fd;
	char	*read;
	size_t	len;

	if (!ft_strstr(link_map, ".ber"))
		return (1);
	printf("%s\n", link_map);
	fd = open(link_map, O_RDONLY);
	if (fd == -1)
		printf("file not found\n");
	read = ft_strdup("");
	while (read != NULL)
	{
		read = get_next_line(fd);
		printf("%s\n", read);
		data->map.size_y++;
	}
	printf("%d\n", data->map.size_y);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("error argument!\n");
	}
	if (read_map(argv[1], &data))
		printf("error map format\n");
	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 500, 500, "so_long");
	mlx_loop(data.mlx.mlx);
}
