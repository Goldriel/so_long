/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:54:18 by jarrakis          #+#    #+#             */
/*   Updated: 2022/01/30 21:15:24 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *link_map, t_data *data)
{
	int		fd;
	char	*read_buf;
	int		byet_read;
	char	*str;

	byet_read = 1;
	if (!ft_strstr(link_map, ".ber"))
		return (1);
	printf("%s\n", link_map);
	fd = open(link_map, O_RDONLY);
	if (fd == -1)
		printf("file not found\n");
	read_buf = malloc(sizeof(char *) * 1 + 1);
	if (read_buf == NULL)
		return (-2);
	*(read_buf + 1) = '\0';
	while (byet_read != 0)
	{
		byet_read = read(fd, read_buf, 1);
		if (byet_read == 0)
			break ;
		str = ft_strjoin(str, read_buf);
		data->map.map = ft_split(str, '\n');
	}
	//printf("%d\n", data->map.size_y);
	free(str);
	free(read_buf);
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
