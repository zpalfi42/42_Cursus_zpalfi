/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:44:26 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/23 15:47:12 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_comand(char **mypaths, char *cmd)
{
	char	*tmp;
	char	*comand;

	while (*mypaths)
	{
		tmp = ft_strjoin(*mypaths, "/");
		comand = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(comand, 0) == 0)
			return (comand);
		free(comand);
		mypaths++;
	}
	return (NULL);
}

void	process_child_1(t_pipex *data, char **argv, char **envp)
{
	dup2(data->end[1], 1);
	close(data->end[0]);
	dup2(data->f1, 0);
	data->mycmdargs = ft_split(argv[2], ' ');
	data->comand = get_comand(data->mypaths, data->mycmdargs[0]);
	if (!data->comand)
	{
		free_childs(data);
		ft_error("Error: Command not found\n");
		exit(1);
	}
	execve(data->comand, data->mycmdargs, envp);
}

void	process_child_2(t_pipex *data, char **argv, char **envp)
{
	dup2(data->end[0], 0);
	close(data->end[1]);
	dup2(data->f2, 1);
	data->mycmdargs = ft_split(argv[3], ' ');
	data->comand = get_comand(data->mypaths, data->mycmdargs[0]);
	if (!data->comand)
	{
		free_childs(data);
		ft_error("Error: Command not found\n");
		exit(1);
	}
	execve(data->comand, data->mycmdargs, envp);
}
