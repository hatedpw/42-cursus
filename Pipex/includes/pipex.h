/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:23:33 by knicks            #+#    #+#             */
/*   Updated: 2022/02/16 17:00:19 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* write, read, close,access, pipe, dup/dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>

/* malloc, free, EXIT */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid/wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* perror */
# include <stdio.h>
# include <errno.h>
# include "../includes/libft.h"

char	*get_path(char **envp, char *arg);
void	error(char *name, char *err);

#endif
