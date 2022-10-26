/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:38:20 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:39:00 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static void	exec_first(t_data *data, int *pipe_fd)
{
	int		fd;

	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit(2);
	if (data->pid[0] == 0 && data->cmds[0].path != NULL
		&& ft_strncmp(data->infile, "/dev/null", ft_strlen(data->infile)) != 0)
	{
		fd = open(data->infile, O_RDONLY);
		dup2(fd, STDIN);
		close(fd);
		data->num_exec = -1;
		dup2(pipe_fd[WRITE], STDOUT);
		close(pipe_fd[READ]);
		close(pipe_fd[WRITE]);
		if (execve(data->cmds[0].path, data->cmds[0].args, data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

static void	exec_last(t_data *data, int *pipe_fd)
{
	int	fd;

	fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_error(ERR_CANNOT_OPEN_FILE, data->outfile);
		data->exit_value = 1;
	}
	dup2(fd, STDOUT);
	close(fd);
	data->pid[1] = fork();
	if (data->pid[1] < 0)
		exit (3);
	if (data->pid[1] == 0 && data->cmds[1].path != NULL)
	{
		data->num_exec = -1;
		dup2(pipe_fd[READ], STDIN);
		close(pipe_fd[READ]);
		close(pipe_fd[WRITE]);
		if (execve(data->cmds[1].path, data->cmds[1].args, data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

void	exec_cmds(t_data *data, int *pipe_fd)
{
	if (data->num_exec == 0)
		exec_first(data, pipe_fd);
	else
		exec_last(data, pipe_fd);
}
