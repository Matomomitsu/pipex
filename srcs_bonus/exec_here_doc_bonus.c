/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:04:06 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:42:36 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	get_stdin(t_data *data)
{
	char	*gnl;
	size_t	limiter_len;

	limiter_len = ft_strlen(data->infile);
	data->pid[0] = fork();
	if (data->pid[0] < 0)
		exit(2);
	if (data->pid[0] == 0)
	{
		data->num_exec = -1;
		ft_putstr_fd("> ", STDIN);
		gnl = get_next_line(STDIN);
		while (ft_strncmp(gnl, data->infile, limiter_len) != 0 \
		|| gnl[limiter_len] != '\n')
		{
			ft_putstr_fd("> ", STDIN);
			ft_putstr_fd(gnl, data->pipe_fd[0][WRITE]);
			free(gnl);
			gnl = get_next_line(STDIN);
		}
		free(gnl);
		close_pipes(data);
	}
}

void	exec_first_here_doc(t_data *data, int num_cmd)
{
	data->pid[num_cmd + 1] = fork();
	if (data->pid[num_cmd + 1] < 0)
		exit(2);
	if (data->pid[num_cmd + 1] == 0 && data->cmds[num_cmd].path != NULL)
	{
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd][READ], STDIN);
		dup2(data->pipe_fd[num_cmd + 1][WRITE], STDOUT);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

void	exec_last_here_doc(t_data *data, int num_cmd)
{
	int	fd;

	fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_error(ERR_CANNOT_OPEN_FILE, data->outfile);
		data->exit_value = 1;
	}
	dup2(fd, STDOUT);
	close(fd);
	data->pid[num_cmd + 1] = fork();
	if (data->pid[num_cmd + 1] < 0)
		exit (2);
	if (data->pid[num_cmd + 1] == 0 && data->cmds[num_cmd].path != NULL)
	{
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd][READ], STDIN);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}

void	exec_cmd_here_doc(t_data *data, int num_cmd)
{
	data->pid[num_cmd + 1] = fork();
	if (data->pid[num_cmd + 1] < 0)
		exit (2);
	if (data->pid[num_cmd + 1] == 0 && data->cmds[num_cmd].path != NULL)
	{
		data->num_exec = -1;
		dup2(data->pipe_fd[num_cmd][READ], STDIN);
		dup2(data->pipe_fd[num_cmd + 1][WRITE], STDOUT);
		close_pipes(data);
		if (execve(data->cmds[num_cmd].path, data->cmds[num_cmd].args, \
		data->envp))
			ft_error(ERR_EXECVE, data);
	}
	else
		data->num_exec++;
}
