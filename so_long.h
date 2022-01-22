/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:54:14 by jarrakis          #+#    #+#             */
/*   Updated: 2022/01/22 22:09:34 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_mms/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

#endif