/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_here_doc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:10:57 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:15:49 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	wait_child(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < data->num_cmds - 1)
		waitpid(data->pid[i], NULL, 0);
	waitpid(data->pid[i], &status, 0);
	if (data->exit_value == 0)
		data->exit_value = WEXITSTATUS(status);
	if (data->cmds[i].path == NULL && data->cmds[i].args[0] != NULL)
		data->exit_value = 127;
}

static void	exec_cmds_here_doc(t_data *data, int num_cmd)
{
	if (data->num_exec == 0)
		exec_first_here_doc(data, num_cmd);
	else
	{
		if (data->num_exec == data->num_cmds - 1)
			exec_last_here_doc(data, num_cmd);
		else
			exec_cmd_here_doc(data, num_cmd);
	}
}

static void	init_cmds_here_doc(t_data *data)
{
	int	i;

	i = 0;
	data->cmds = (t_cmd *)ft_calloc(data->num_cmds, sizeof(t_cmd));
	while (i <= data->num_cmds - 1)
	{
		data->cmds[i].args = argument_parser(data->argv[3 + i]);
		data->cmds[i].path = find_path(data->paths, data->cmds[i].args[0]);
		i++;
	}
	i = 0;
	while (i <= data->num_cmds - 1)
	{
		if (data->cmds[i].path != NULL)
		{
			data->cmds[i].args[0] = ft_realloc(data->cmds[i].args[0], \
			ft_strlen(data->cmds[i].path) + 1);
			ft_strlcpy(data->cmds[i].args[0], data->cmds[i].path, \
			ft_strlen(data->cmds[i].path) + 1);
		}
		i++;
	}
}

static void	exec_here_doc(t_data *data)
{
	int	i;
	int	return_value;

	init_cmds_here_doc(data);
	get_stdin(data);
	i = 0;
	while (data->num_exec != data->num_cmds && data->num_exec != -1)
	{
		exec_cmds_here_doc(data, i);
		i++;
	}
	close_pipes(data);
	if (data->num_exec != -1)
		wait_child(data);
	return_value = data->exit_value;
	free(data->pipe_fd[data->num_cmds]);
	free_data(data);
	exit(return_value);
}

void	init_here_doc(int argc, char **argv, char **envp, t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->infile = argv[2];
	data->outfile = argv[argc - 1];
	data->num_cmds = argc - 3;
	data->pid = (pid_t *)ft_calloc(sizeof(pid_t), data->num_cmds);
	init_pipe(data);
	data->num_cmds = argc - 4;
	data->num_exec = 0;
	data->paths = get_paths(envp);
	data->exit_value = 0;
	exec_here_doc(data);
}
