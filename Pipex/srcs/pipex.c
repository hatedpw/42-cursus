/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:32:43 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:02:56 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(char **cmd, char **envp)
{
	char	*path;

	if (!ft_strchr(cmd[0], '/'))
	{
		path = get_path(envp, cmd[0]);
		execve(path, cmd, envp);
		error(cmd[0], "command not found");
	}
	else
	{
		path = cmd[0];
		if (access(path, X_OK))
			error(path, strerror(errno));
		else
			execve(path, cmd, envp);
	}
}

/* splits arg, executes and frees, returns exitcode 127 
if fails. 127 is IBM code for cant be found */
static void	run_cmd(char *arg, char **envp)
{
	char	**cmd;
	int		i;

	i = 0;
	if (*arg)
	{
		cmd = ft_split(arg, ' ');
		execute(cmd, envp);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}
	else
	{
		error("", "command not found");
	}
	exit(127);
}

static void	create_pipe(int fd1, int fd2, char **argv, char **envp)
{
	int		fd[2];
	int		id;

	id = 1;
	pipe(fd);
	if (fd1 != -1)
		id = fork();
	if (id == 0)
	{
		dup2(fd1, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		run_cmd(argv[2], envp);
	}
	else
	{
		dup2(fd2, 1);
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
		run_cmd(argv[3], envp);
	}
}

/* 
O_CREAT = pathname doesnt exist then creates reg file
O_WRONLY = open for writing only
O_TRUNC = truncate file to 0
00644 perms are u(w/r)g(w/r)o(w)
issues when testing with other perm levels */
int	main(int argc, char **argv, char *envp[])
{
	int	file1;
	int	file2;

	if (argc == 5)
	{
		file1 = open(argv[1], O_RDONLY);
		if (file1 == -1)
			error(argv[1], strerror(errno));
		file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
		if (file2 == -1)
		{
			error(argv[4], strerror(errno));
			return (1);
		}
		create_pipe(file1, file2, argv, envp);
	}
	ft_putstr_fd("Invalid arguements\n", 2);
	return (1);
}
