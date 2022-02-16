/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:51:44 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:02:06 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*parse_path(char *path, char *arg)
{
	char	*exec;
	char	*tmp;
	int		i;

	i = 0;
	while (path[i] && path[i] != ':')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		exit(0);
	ft_bzero(tmp, i + 2);
	i = 0;
	while (*path && *path != ':')
	{
		tmp[i++] = *path++;
	}
	tmp[i] = '/';
	exec = ft_strjoin(tmp, arg);
	free(tmp);
	return (exec);
}

char	*get_path(char **envp, char *arg)
{
	int		i;
	char	*path;
	char	*exec;

	i = 0;
	path = NULL;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (arg);
	path = envp[i] + 5;
	while (*path)
	{
		if (path == envp[i] + 5 || *path == ';')
		{
			exec = parse_path(path, arg);
			if (!access(exec, F_OK))
				return (exec);
			free(exec);
		}
		path++;
	}
	return (arg);
}

void	error(char *name, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}
