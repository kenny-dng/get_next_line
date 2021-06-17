/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:07:09 by chduong           #+#    #+#             */
/*   Updated: 2021/06/17 12:21:52 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	static char *save;
	
	*line = NULL;
	if (save)
	{
		*line = get_line(save);
		printf("3.save : [%s]\n", save);
		free(save);
		save = NULL;
	}
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		printf("buff : [%s]\n", buff);
		save = get_save(*line, buff);
		printf("save : [%s]\n", save);
		free(*line);
		*line = get_line(save);
		printf("line : [%s]\n", *line);
		if (i_return(save))
		{
			checkrest(save);
			printf("2.save : [%s]\n", save);
			break ;
		}
		free(save);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret == 0)
		return (0);
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		exec;
	int		i;

	i = 1;
	line = NULL;
	fd = open("test42", O_RDONLY);
	
	exec = get_next_line(fd, &line);
	while (exec > 0)
	{
		printf("%d : [%s]\n", i++, line);
		printf("exec : %d\n", exec);
		printf("__________________________________________________________\n\n");
		free(line);
		exec = get_next_line(fd, &line);
	}
	printf("%d : [%s]\n", i++, line);
	printf("exec : %d\n", exec);
	printf("__________________________________________________________\n\n");
	
	free(line);
	close(fd);
	// system("leaks a.out");
	return (0);
}
