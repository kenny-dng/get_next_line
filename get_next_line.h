/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:11:46 by chduong           #+#    #+#             */
/*   Updated: 2021/06/17 12:12:39 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_strlen( char *s);
char	*get_save(char *line, char *buff);
int		i_return(char *s);
int		get_next_line(int fd, char **line);
char	*get_line(char *s);
void	checkrest(char *s);

#endif