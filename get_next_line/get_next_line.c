/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knicks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:13:44 by knicks            #+#    #+#             */
/*   Updated: 2022/01/12 23:45:06 by knicks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*  ret is assigned value by calling 
* read functions with fd, buf and macro (buffer_SIZE)
*  if ret is equal to 0, the end of file has been reached.
* if ret is equal to -1, an error has occured.
* if remain has no value, it is assigned the value of empty str.
* tmp is assigned the value of remain.
* remained assigned to new value via strjoin, attaching a buffer at the end. 
* tmp is FREE'd.
* if a newline char is found in the buffer it stops.
* then returns static char remain. 
*/

static char	*read_and_append(int fd, char *buf, char *remain)
{
	int				ret;
	char			*tmp;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		if (!remain)
			remain = ft_strdup("");
		tmp = remain;
		remain = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (remain);
}

static char	*renew_line(char *line)
{
	size_t	i;
	char	*remain;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	remain = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remain == '\0')
	{
		free(remain);
		remain = NULL;
	}
	line[i + 1] = '\0';
	return (remain);
}

/* returns line, remain is static char that holds remaining string. 
* returns 0 if undefined input
* assigns value to different variables.
* alloc in mem for buffer then free post usage.
*/
char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_and_append(fd, buff, remain);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	remain = renew_line(line);
	return (line);
}
