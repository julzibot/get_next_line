/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:20:05 by jibot             #+#    #+#             */
/*   Updated: 2021/11/19 22:05:58 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

int	is_line(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	else
		return (0);
}

int get_save(char *buffer, char *save)
{
	int i;

	i = 0;
	if (!save)
		return (0);
	else
	{
		while (save[i])
		{
			buffer[i] = save[i];
			i++;
		}
		return (i);
	}
}

/*char	*get_full_line(char *save, int fd)
{
}*/

char	*get_next_line(int fd)
{
	char				buffer[BUFFER_SIZE + 1];
	static char			*save;
	char				*line;
	int					i;
	
	i = get_save(buffer, save);
	read(fd, buffer + i, BUFFER_SIZE - i);
	buffer[BUFFER_SIZE] = '\0';
	if (is_line(buffer) != 0)
	{
		save = ft_strdup(buffer + is_line(buffer) + 1);
		buffer[is_line(buffer) + 1] = '\0';
		return (ft_strdup(buffer));
	}
	else
	{
		save = ft_strdup(buffer);
		while (is_line(save) == 0)
		{
			buffer[i] = '\0';
			read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = '\0';
			save = ft_strjoin(save, buffer);
		}
		line = ft_strdup(save);
		save = ft_strdup(save + is_line(save) + 1);
		line[is_line(line) + 1] = '\0';
		return (line);
	}
}

int	main(void)
{
	int	fd = open("testdoc.txt", O_RDONLY);
	int i = 0;
	char	*line;

	while (i++ < 9)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	//fd = close(fd);
}
