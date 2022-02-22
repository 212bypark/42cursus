/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:56:15 by bypark            #+#    #+#             */
/*   Updated: 2021/05/19 20:32:08 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_crl(char *backup)
{
	int		index;

	index = 0;
	while (backup[index])
	{
		if (backup[index] == '\n')
		{
			backup[index] = '\0';
			return (index);
		}
		index++;
	}
	return (-1);
}

static int	ft_cut(char **backup, int index, char **line)
{
	char	*temp;
	int		flag;

	flag = 0;
	*line = ft_strdup(*backup, &flag);
	if (flag)
		return (-1);
	temp = ft_strdup(*backup + index + 1, &flag);
	if (flag)
		return (-1);
	free(*backup);
	*backup = temp;
	return (1);
}

static int	ft_return(char **backup, char **line, int read_size)
{
	int		index;
	int		flag;

	flag = 0;
	if (read_size < 0)
		return (-1);
	if (*backup)
	{
		if ((index = ft_find_crl(*backup)) >= 0)
			return (ft_cut(backup, index, line));
		else
		{
			*line = ft_strdup(*backup, &flag);
			if (flag)
				return (-1);
			free(*backup);
			*backup = 0;
			return (0);
		}
	}
	*line = ft_strdup("", &flag);
	if (flag)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_size;
	int			index;
	int			flag;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	flag = 0;
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buffer, &flag);
		if (flag)
			return (-1);
		if ((index = ft_find_crl(backup[fd])) >= 0)
			return (ft_cut(&backup[fd], index, line));
	}
	return (ft_return(&backup[fd], line, read_size));
}
