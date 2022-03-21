/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:29 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/02 15:43:55 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	start_draw(t_fdf *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1280, 1024, "FdF");
	if (!data->win_ptr)
		return (1);
	if (draw(data) != 0)
		return (1);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	points_get(t_fdf *data, int mode)
{
	if (mode == 1)
	{
		data->x0 = data->x;
		data->x1 = data->x + 1;
		data->y0 = data->y;
		data->y1 = data->y;
	}
	if (mode == 2)
	{
		data->x0 = data->x;
		data->x1 = data->x;
		data->y0 = data->y;
		data->y1 = data->y + 1;
	}
}
