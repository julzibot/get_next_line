/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:22:53 by jibot             #+#    #+#             */
/*   Updated: 2021/11/25 16:08:54 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

//_______________GNL_FUNCTIONS_______________//

char	*get_next_line(int fd);
char	*ft_strdup(char const *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

#endif
