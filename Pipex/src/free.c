/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:23:32 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/23 15:46:50 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(t_pipex *data)
{
	int	i;

	i = 0;
	close(data->f1);
	close(data->f2);
	while (data->mypaths[i])
	{
		free(data->mypaths[i]);
		i++;
	}
	free(data->mypaths);
}

void	free_childs(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->mycmdargs[i])
	{
		free(data->mycmdargs[i]);
		i++;
	}
	free(data->mycmdargs);
	free(data->comand);
}
