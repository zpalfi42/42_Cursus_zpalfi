/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:51:57 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/02 15:44:17 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	map_rows(char *filename)
{
	char	*i;
	int		fd;
	int		rows;

	fd = open(filename, O_RDONLY, 0);
	rows = 0;
	while (1)
	{
		i = get_next_line(fd);
		if (!i)
			break ;
		rows++;
		free(i);
	}
	close(fd);
	return (rows);
}

static int	map_width(char *filename)
{
	char	*i;
	int		fd;
	int		width;

	fd = open(filename, O_RDONLY, 0);
	i = get_next_line(fd);
	width = count_words(i, ' ');
	free(i);
	close(fd);
	return (width);
}

static void	map_z_rows(int *z, char *s)
{
	char	**n;
	int		i;

	n = ft_split(s, ' ');
	i = 0;
	while (n[i])
	{
		z[i] = ft_atoi(n[i]);
		free(n[i]);
		i++;
	}
	free(n);
}

static int	map_z(t_fdf *data, char *filename)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	while (i < data->rows)
	{
		data->z[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->z[i])
			return (1);
		i++;
	}
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		map_z_rows(data->z[i], s);
		free(s);
		i++;
	}
	data->z[i] = NULL;
	return (0);
}

int	read_file(t_fdf *data, char *filename)
{
	data->rows = map_rows(filename);
	data->width = map_width(filename);
	data->z = (int **)malloc(sizeof(int *) * (data->rows + 1));
	if (!data->z)
		return (1);
	return (map_z(data, filename));
}
