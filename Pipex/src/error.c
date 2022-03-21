/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:41 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/23 15:46:39 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror(char *s)
{
	perror(s);
	exit(1);
}

int	ft_error(char *s)
{
	write(2, s, ft_strlen(s));
	return (1);
}
