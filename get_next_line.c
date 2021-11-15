/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:20:05 by jibot             #+#    #+#             */
/*   Updated: 2021/11/15 15:20:50 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_strdup(const char *str);

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE + 1];
	static char			s[1];
	static unsigned int	i;

	//i = 0;
	while (*s != '\n' && i < BUFFER_SIZE + 1)
	{
		read(fd, s, 1);
		buffer[i] = *s;
		i++;
	}
	read(fd, s, 1);
	if (*s == '\n')
	{
		buffer[i] = *s;
		while (++i < BUFFER_SIZE + 1)
			buffer[i] = '\0';
	}
	return (ft_strdup(buffer));
}

int	main(void)
{
	int	fd = open("testdoc.txt", O_RDONLY);

	printf("%s", get_next_line(fd));

	//fd = close(fd);
}
