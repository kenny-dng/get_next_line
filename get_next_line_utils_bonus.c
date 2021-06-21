/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:11:10 by chduong           #+#    #+#             */
/*   Updated: 2021/06/19 14:29:07 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*save_join(char *save, char *buff)
{
	char	*newsave;
	int		i;

	i = 0;
	if (!save && !buff)
		return (NULL);
	newsave = malloc(sizeof(char *) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (!newsave)
		return (NULL);
	while (save && save[i])
	{	
		newsave[i] = save[i];
		++i;
	}
	while (*buff)
	{
		newsave[i++] = *buff;
		++buff;
	}
	newsave[i] = 0;
	free(save);
	return (newsave);
}
