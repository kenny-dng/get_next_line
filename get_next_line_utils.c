/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:11:10 by chduong           #+#    #+#             */
/*   Updated: 2021/06/17 12:07:07 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

int	i_return(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (i);
		++i;
	}
	return (0);
}

char	*get_save(char *line, char *buff)
{
	char	*p;
	int		i;
	
	i = 0;
	if (!line && !buff)
		return (NULL);
	p = malloc(sizeof(char *) * (ft_strlen(line) + ft_strlen(buff) + 1));
	if (!p)
		return (NULL);
	while (line && *line)
	{	
		p[i++] = *line;
		++line;
	}
	while (*buff)
	{
		p[i++] = *buff;
		++buff;
	}
	p[i] = 0;
	return (p);
}

char	*get_line(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		 	break ;
		p[i] = s[i];
		++i;
	}
	p[i] = 0;
	return (p);
}

void	checkrest(char *s)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\n')
		++i;
	++i;
	while (s[i + j])
	{
		s[j] = s[i + j];
		++j;
	}
	s[j] = 0;
}