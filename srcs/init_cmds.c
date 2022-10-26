/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:44:30 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 16:50:39 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static char	*access_path(char *cmd, char **paths)
{
	char	*path;
	int		i;

	i = 0;
	if (cmd)
	{
		while (paths[i] != NULL)
		{
			path = ft_strjoin(paths[i], cmd);
			if (access(path, F_OK | X_OK) == 0)
				return (path);
			free(path);
			i++;
		}
	}
	return (NULL);
}

static char	*find_path(char **paths, char *cmd)
{
	char	*path;
	char	*complete_cmd;

	if (!cmd)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strjoin(cmd, ""));
		else
			ft_error(ERR_CMD_NOT_FOUND, cmd);
	}
	else
	{
		complete_cmd = ft_strjoin("/", cmd);
		path = access_path(complete_cmd, paths);
		free(complete_cmd);
		if (path)
			return (path);
		else
			ft_error(ERR_CMD_NOT_FOUND, cmd);
	}
	return (NULL);
}

void	init_cmds(t_data *data)
{
	int	i;

	i = 0;
	data->cmds = (t_cmd *)ft_calloc(data->num_cmds, sizeof(t_cmd));
	while (i <= data->num_cmds - 1)
	{
		data->cmds[i].args = argument_parser(data->argv[2 + i]);
		data->cmds[i].path = find_path(data->paths, data->cmds[i].args[0]);
		i++;
	}
	i = 0;
	while (i <= data->num_cmds - 1)
	{
		if (data->cmds[i].path != NULL && ft_strncmp(data->cmds[i].path, \
		data->cmds[i].args[0], ft_strlen(data->cmds[i].args[0]) != 0))
		{
			data->cmds[i].args[0] = ft_realloc(data->cmds[i].args[0], \
			ft_strlen(data->cmds[i].path) + 1);
			ft_strlcpy(data->cmds[i].args[0], data->cmds[i].path, \
			ft_strlen(data->cmds[i].path) + 1);
		}
		i++;
	}
}
