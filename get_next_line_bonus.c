/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:07:09 by chduong           #+#    #+#             */
/*   Updated: 2021/06/22 19:31:01 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static int	newline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

static int	stock_buff(int fd, char **save)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		*save = save_join(*save, buff);
		if (newline(buff) > -1)
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret > 0)
		return (1);
	return (ret);
}

static void	save_rest(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		++i;
	++i;
	while (s[i])
		s[j++] = s[i++];
	s[j] = 0;
}

static char	*get_line(char *s)
{
	char	*line;
	int		len;
	size_t	i;

	i = 0;
	len = newline(s);
	if (len < 0)
		len = ft_strlen(s);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				break ;
			line[i] = s[i];
			++i;
		}	
		save_rest(s);
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int			output;
	static char	*save[1024];

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	output = 1;
	if (!save[fd] || newline(save[fd]) < 0)
		output = stock_buff(fd, &save[fd]);
	if (output > -1)
		*line = get_line(save[fd]);
	if (output == 0 && save[fd])
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	if (!*line)
		return (-1);
	return (output);
}