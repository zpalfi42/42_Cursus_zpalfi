/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:29 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/02 15:45:26 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_data(t_fdf *data)
{
	int	i;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	i = 0;
	while (i < data->rows)
	{
		free(data->z[i]);
		i++;
	}
	free(data);
	exit (0);
}

static void	restart_draw(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	start_draw(data);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->y_move -= 10;
	if (key == 125)
		data->y_move += 10;
	if (key == 123)
		data->x_move -= 10;
	if (key == 124)
		data->x_move += 10;
	if (key == 13)
		data->z_move++;
	if (key == 1)
		data->z_move--;
	if (key == 14)
		data->zoom -= 2;
	if (key == 12)
		data->zoom += 2;
	if (key == 53)
		free_data(data);
	restart_draw(data);
	return (0);
}

static int	init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->zoom = 2;
	data->x_move = 450;
	data->y_move = 150;
	data->z_move = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (ft_error("Error: Invalid number of arguments"));
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (read_file(data, argv[1]) != 0)
		return (ft_error("Error: Failed file reading"));
	if (init(data) != 0)
		return (ft_error("Error: Failed initiation"));
	if (start_draw(data) != 0)
		return (ft_error("Error: Failed drawing"));
	return (0);
}
