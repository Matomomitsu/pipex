/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:54:09 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 19:46:40 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "errors.h"

typedef struct s_cmd
{
	char		*path;
	char		**args;
}	t_cmd;

typedef struct s_data
{
	int			argc;
	char		**argv;
	pid_t		*pid;
	char		*infile;
	char		*outfile;
	char		**envp;
	int			num_cmds;
	int			num_exec;
	char		**paths;
	int			exit_value;
	int			**pipe_fd;
	t_cmd		*cmds;
}	t_data;

// Exec_bonus.c

void	exec_cmds(t_data *data, int num_cmd);

// Init_cmds_bonus.c

void	init_cmds(t_data *data);
char	*find_path(char **paths, char *cmd);

// Pipex_bonus.c

void	free_data(t_data *data);
char	**get_paths(char **envp);
void	init_pipe(t_data *data);

// Error_bonus.c

void	ft_error(int error, void *data);
void	handle_args(int argc);
void	free_data(t_data *data);
void	close_pipes(t_data *data);

// Argument_parser_bonus.c

char	**argument_parser(char const *s);

// Argument_parser2_bonus.c

void	putchar_str(char const *s, char **str, size_t countc);

// Init_here_doc_bonus.c

void	init_here_doc(int argc, char **argv, char **envp, t_data *data);
void	wait_child(t_data *data);

// Exec_here_doc_bonus.c

void	exec_first_here_doc(t_data *data, int num_cmd);
void	exec_last_here_doc(t_data *data, int num_cmd);
void	exec_cmd_here_doc(t_data *data, int num_cmd);
void	get_stdin(t_data *data);

# define READ 0
# define WRITE 1
# define STDOUT	STDOUT_FILENO
# define STDIN	STDIN_FILENO
# define STDERR	STDERR_FILENO

#endif
