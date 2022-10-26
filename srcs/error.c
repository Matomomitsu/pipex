/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:48:07 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:38:05 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	handle_args(int argc)
{
	if (argc != 5)
		ft_error(ERR_ARGS, NULL);
}

void	ft_error(int error, void *name)
{
	if (error == ERR_CANNOT_OPEN_FILE)
		ft_printf(STDERR, "pipex: %s: %s\n", name, strerror(errno));
	if (error == ERR_ARGS)
	{
		ft_putstr_fd("Invalid number of arguments\n", STDERR);
		exit(1);
	}
	if (error == ERR_CMD_NOT_FOUND)
		ft_printf(STDERR, "pipex: %s: command not found\n", name);
	if (error == ERR_EXECVE)
	{
		ft_printf(STDERR, "pipex: error to execute execve\n");
		free_data(name);
		exit(error);
	}
}
