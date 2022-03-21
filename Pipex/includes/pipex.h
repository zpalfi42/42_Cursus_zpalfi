/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:24:30 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/23 15:51:40 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		f1;
	int		f2;
	int		end[2];
	char	*envpaths;
	char	*comand;
	char	**mypaths;
	char	**mycmdargs;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_error(char *s);

void	ft_perror(char *s);
void	process_child_1(t_pipex *data, char **argv, char **envp);
void	process_child_2(t_pipex *data, char **argv, char **envp);
void	ft_free(t_pipex *data);
void	free_childs(t_pipex *data);

size_t	ft_strlen(const char *s);

#endif
