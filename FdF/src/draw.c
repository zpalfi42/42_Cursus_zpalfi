/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:13:16 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/02 15:43:44 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	get_max(float dx, float dy)
{
	if (dx < 0 && dy < 0)
	{
		if (dx < dy)
			return (-dx);
		return (-dy);
	}
	else if (dx < 0)
	{
		if (-dx > dy)
			return (-dx);
		return (dy);
	}
	else if (dy < 0)
	{
		if (dx > -dy)
			return (dx);
		return (-dy);
	}
	else
	{
		if (dx > dy)
			return (dx);
		return (dy);
	}
}

static void	isometric(t_fdf *data)
{
	int	prev_x;
	int	prev_y;

	prev_x = (int)data->x0;
	prev_y = (int)data->y0;
	data->x0 = (prev_x - prev_y) * cos(0.8);
	data->y0 = (prev_x + prev_y) * sin(0.8) - (data->z1 * data->z_move);
	prev_x = (int)data->x1;
	prev_y = (int)data->y1;
	data->x1 = (prev_x - prev_y) * cos(0.8);
	data->y1 = (prev_x + prev_y) * sin(0.8) - (data->z2 * data->z_move);
}

static void	xy_changes(t_fdf *data)
{
	data->z1 = data->z[(int)data->y0][(int)data->x0];
	data->z2 = data->z[(int)data->y1][(int)data->x1];
	data->x0 *= data->zoom;
	data->y0 *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	isometric(data);
	data->x0 += data->x_move;
	data->y0 += data->y_move;
	data->x1 += data->x_move;
	data->y1 += data->y_move;
}

static void	bresenham_algorithm(t_fdf *data)
{
	float	dx;
	float	dy;
	float	max;

	xy_changes(data);
	dx = data->x1 - data->x0;
	dy = data->y1 - data->y0;
	max = get_max(dx, dy);
	dx = dx / max;
	dy = dy / max;
	while ((int)(data->x1 - data->x0) != 0 || (int)(data->y1 - data->y0) != 0)
	{
		if (data->z1 > 0 || data->z2 > 0)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				(int)data->x0, (int)data->y0, 0xff4242);
		else if (data->z1 < 0 || data->z2 < 0)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				(int)data->x0, (int)data->y0, 0x4242ff);
		else
			mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				(int)data->x0, (int)data->y0, 0xffffff);
		data->x0 += dx;
		data->y0 += dy;
	}
}

int	draw(t_fdf *data)
{
	data->y = 0;
	while (data->y < data->rows)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if ((int)data->x < data->width - 1)
			{
				points_get(data, 1);
				bresenham_algorithm(data);
			}
			if ((int)data->y < data->rows - 1)
			{
				points_get(data, 2);
				bresenham_algorithm(data);
			}
			data->x++;
		}
		data->y++;
	}
	return (0);
}
