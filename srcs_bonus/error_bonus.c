/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:55:19 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:39:31 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	handle_args(int argc)
{
	if (argc < 5)
		ft_error(ERR_ARGS, NULL);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds)
	{
		close(data->pipe_fd[i][READ]);
		close(data->pipe_fd[i][WRITE]);
		i++;
	}
}

void	free_data(t_data *data)
{
	int	i;
	int	o;

	i = 0;
	while (data->paths[i] != NULL)
		free(data->paths[i++]);
	free(data->paths[i]);
	free(data->paths);
	i = 0;
	while (i < data->num_cmds)
	{
		o = 0;
		while (data->cmds[i].args[o] != NULL)
			free(data->cmds[i].args[o++]);
		free(data->cmds[i].args[o]);
		free(data->cmds[i].args);
		free(data->cmds[i].path);
		free(data->pipe_fd[i]);
		i++;
	}
	free(data->pipe_fd);
	free(data->pid);
	free(data->cmds);
	free(data);
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
