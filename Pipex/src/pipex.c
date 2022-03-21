/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:03:10 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/23 15:51:15 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_envp_paths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static int	init(t_pipex *data, char **argv, char **envp)
{
	data->f1 = open(argv[1], O_RDONLY);
	if (data->f1 < 0)
		ft_perror("Infile");
	data->f2 = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->f2 < 0)
		ft_perror("Outfile");
	if (pipe(data->end) < 0)
		ft_perror("Pipe");
	data->envpaths = find_envp_paths(envp);
	data->mypaths = ft_split(data->envpaths, ':');
	return (0);
}

static int	pipex(t_pipex *data, char **argv, char **envp)
{
	data->pid1 = fork();
	if (data->pid1 < 0)
		ft_perror("Fork: ");
	if (data->pid1 == 0)
		process_child_1(data, argv, envp);
	data->pid2 = fork();
	if (data->pid2 < 0)
		ft_perror("Fork: ");
	if (data->pid2 == 0)
		process_child_2(data, argv, envp);
	close(data->end[0]);
	close(data->end[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	ft_free(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
		return (ft_error("Error: Invalid number of arguments\n"));
	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (!data)
		return (ft_error("Error: Failed data malloc"));
	if (init(data, argv, envp) != 0)
		return (0);
	if (pipex(data, argv, envp) != 0)
		return (0);
	return (0);
}
