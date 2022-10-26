/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:52:11 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/23 16:04:06 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	t_cmd		*cmds;
}	t_data;

// Exec.c

void	exec_cmds(t_data *data, int *pipe_fd);

// Init_cmds.c

void	init_cmds(t_data *data);

// Main.c

void	free_data(t_data *data);

// Error.c

void	ft_error(int error, void *name);
void	handle_args(int argc);

// Argument_parser.c

char	**argument_parser(char const *s);

// Argument_parser2.c

void	putchar_str(char const *s, char **str, size_t countc);

# define READ 0
# define WRITE 1
# define STDOUT	STDOUT_FILENO
# define STDIN	STDIN_FILENO
# define STDERR	STDERR_FILENO

#endif
