/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:20:05 by jibot             #+#    #+#             */
/*   Updated: 2021/11/24 19:01:01 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	is_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i);
	else
		return (0);
}

int get_save(char *buffer, char *save)
{
	int 		i;
	static int	flag;

	i = 0;
	if (!save && flag != 0)
		return (-1);
	else if (!save && flag == 0)
	{
		return (0);
		flag++;
	}
	while (save[i])
	{
		buffer[i] = save[i];
		i++;
	}
	return (i);
}

char	*get_full_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nbyte;

	while (!is_line(line))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte == 0)
			return (line);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char				buffer[BUFFER_SIZE + 1];
	static char			*save;
	char				*line;
	int					i;
	int					nbyte;

	i = get_save(buffer, save);
	ft_bzero(buffer + i, BUFFER_SIZE - i + 1);
	nbyte = read(fd, buffer + i, BUFFER_SIZE - i);
	if (i == -1 || !buffer[0] || nbyte < 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	else if (is_line(buffer) > 0 || buffer[0] == '\n')
		line = ft_strdup(buffer);
	else
		line = get_full_line(ft_strdup(buffer), fd);
	free(save);
	if (is_line(line) && line[ft_strlen(line) - 1] != '\n')
	{
		save = ft_strdup(line + is_line(line) + 1);
		line[is_line(line) + 1] = '\0';
	}
	else
		save = NULL;
	return (line);
	/*else if (is_line(buffer) > 0 || buffer[0] == '\n')
	{
		free(save);
		if (buffer[BUFFER_SIZE - 1] == '\n')
			save = NULL;
		else
			save = ft_strdup(buffer + is_line(buffer) + 1);
		buffer[is_line(buffer) + 1] = '\0';
		return (ft_strdup(buffer));
	}
	else
	{
		line = get_full_line(ft_strdup(buffer), fd);
		free(save);
		if (is_line(line) && line[ft_strlen(line) - 1] != '\n')
		{
			save = ft_strdup(line + is_line(line) + 1);
			line[is_line(line) + 1] = '\0';
		}
		else
			save = NULL;
		return (line);
	}*/
}

/*int	main(void)
{
	int	fd = open("testdoc.txt", O_RDONLY);
	//int	fd = open("3char.txt", O_RDONLY);
	//int	fd = open("BUFFER_SIZEnl.txt", O_RDONLY);
	//int	fd = open("41_no_nl.txt", O_RDONLY);
	//int	fd = open("41_with_nl.txt", O_RDONLY);
	int i = 0;
	char	*line;

	while (i++ < 20)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	//close(fd);
}*/
