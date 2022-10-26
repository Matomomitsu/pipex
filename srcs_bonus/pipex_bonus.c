/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:56:56 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 06:36:53 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

char	**get_paths(char **envp)
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

void	init_pipe(t_data *data)
{
	int	i;

	i = 0;
	data->pipe_fd = (int **)ft_calloc(sizeof(int *), data->num_cmds);
	while (i < data->num_cmds)
	{
		data->pipe_fd[i] = (int *)ft_calloc(sizeof(int), 3);
		if (!data->pipe_fd[i])
			exit(6);
		if (pipe(data->pipe_fd[i]) == -1)
			exit (7);
		i++;
	}
}

static void	exec_data(t_data *data)
{
	int	i;
	int	return_value;

	init_cmds(data);
	i = 0;
	while (data->num_exec != data->num_cmds && data->num_exec != -1)
	{
		exec_cmds(data, i);
		i++;
	}
	close_pipes(data);
	if (data->num_exec != -1)
		wait_child(data);
	return_value = data->exit_value;
	free_data(data);
	exit(return_value);
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
	data->outfile = argv[argc - 1];
	data->num_cmds = argc - 3;
	data->num_exec = 0;
	data->pid = (pid_t *)ft_calloc(sizeof(pid_t), data->num_cmds);
	init_pipe(data);
	data->paths = get_paths(envp);
	data->exit_value = 0;
	exec_data(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	handle_args(argc);
	data = (t_data *)malloc(sizeof(t_data));
	if (ft_strncmp(argv[1], "here_doc", strlen("here_doc")) == 0)
		init_here_doc(argc, argv, envp, data);
	else
		init_data(argc, argv, envp, data);
	return (0);
}
