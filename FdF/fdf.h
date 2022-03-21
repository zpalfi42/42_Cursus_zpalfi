/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:57 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/02 15:34:18 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct t_fdf
{
	int		width;
	int		rows;
	int		**z;
	int		z1;
	int		z2;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	float	zoom;	
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	x_move;
	float	y_move;
	float	z_move;
}	t_fdf;

void	points_get(t_fdf *data, int mode);
int		read_file(t_fdf *data, char *filename);
int		start_draw(t_fdf *data);
int		draw(t_fdf *data);
int		ft_error(char *error);
int		deal_key(int key, t_fdf *data);

#endif
