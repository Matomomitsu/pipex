/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:16:01 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 20:15:57 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

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
	while (i <= data->num_cmds - 1)
	{
		o = 0;
		while (data->cmds[i].args[o] != NULL)
			free(data->cmds[i].args[o++]);
		free(data->cmds[i].path);
		free(data->cmds[i].args[o]);
		free(data->cmds[i].args);
		i++;
	}
	free(data->pid);
	free(data->cmds);
	free(data);
}

static char	**get_paths(char **envp)
{
	size_t	i;
	char	**paths;
	char	*trim_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	trim_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(trim_path, ':');
	free(trim_path);
	return (paths);
}

static void	init_data(int argc, char **argv, char **envp, t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->infile = argv[1];
	if (access(data->infile, F_OK | R_OK) != 0)
	{
		ft_error(ERR_CANNOT_OPEN_FILE, data->infile);
		data->infile = "/dev/null";
	}
	data->pid = (pid_t *)ft_calloc(sizeof(pid_t), 2);
	data->outfile = argv[argc - 1];
	data->num_cmds = argc - 3;
	data->num_exec = 0;
	data->paths = get_paths(envp);
	data->exit_value = 0;
}

void	wait_child(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < data->num_cmds - 1 && data->pid[i])
		waitpid(data->pid[i], NULL, 0);
	waitpid(data->pid[i], &status, 0);
	if (data->exit_value == 0)
		data->exit_value = WEXITSTATUS(status);
	if (data->cmds[1].path == NULL && data->cmds[1].args[0] != NULL)
		data->exit_value = 127;
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	t_data	*data;
	int		i;
	int		return_value;

	handle_args(argc);
	data = (t_data *)malloc(sizeof(t_data));
	init_data(argc, argv, envp, data);
	init_cmds(data);
	if (pipe(pipe_fd) == -1)
		return (1);
	i = 0;
	while (data->num_exec != data->num_cmds && data->num_exec != -1)
	{
		exec_cmds(data, pipe_fd);
		i++;
	}
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	if (data->num_exec != -1)
		wait_child(data);
	return_value = data->exit_value;
	free_data(data);
	return (return_value);
}
