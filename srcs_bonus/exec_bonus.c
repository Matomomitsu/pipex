/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:55:49 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:40:51 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

static void	exec_first(t_data *data, int num_cmd)
{
	int		fd;

	data->pid[num_cmd] = fork();
	if (data->pid[num_cmd] < 0)
		exit(2);
	if (data->pid[num_cmd] == 0 && data->cmds[num_cmd].path != NULL
		&& ft_strncmp(data->infile, "/dev/null", ft_strlen(data->infile)) != 0)
	{
		fd = open(data->infile, O_RDONLY);
		dup2(fd, STDIN);
		close(fd);
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd][WRITE], STDOUT);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

static void	exec_last(t_data *data, int num_cmd)
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
	data->pid[num_cmd] = fork();
	if (data->pid[num_cmd] < 0)
		exit (3);
	if (data->pid[num_cmd] == 0 && data->cmds[num_cmd].path != NULL)
	{
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd - 1][READ], STDIN);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

static void	exec_cmd(t_data *data, int num_cmd)
{
	data->pid[num_cmd] = fork();
	if (data->pid[num_cmd] < 0)
		exit (3);
	if (data->pid[num_cmd] == 0 && data->cmds[num_cmd].path != NULL)
	{
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd - 1][READ], STDIN);
		dup2(data->pipe_fd[num_cmd][WRITE], STDOUT);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

void	exec_cmds(t_data *data, int num_cmd)
{
	if (data->num_exec == 0)
		exec_first(data, num_cmd);
	else
	{
		if (data->num_exec == data->num_cmds - 1)
			exec_last(data, num_cmd);
		else
			exec_cmd(data, num_cmd);
	}
}
