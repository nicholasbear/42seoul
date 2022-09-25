/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:55:15 by wookim2           #+#    #+#             */
/*   Updated: 2022/08/22 16:03:34 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *s)
{
	size_t	i;

	if (!s)
		return (-2);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i);
	return (-1);
}

char	*nl_inline(char **back_up, int place)
{
	char	*line;
	char	*new_back_up;

	new_back_up = ft_strdup(*back_up + place + 1);
	line = (char *)malloc(sizeof(char) * place + 2);
	if (!line)
	{
		free(new_back_up);
		return (NULL);
	}
	ft_strlcpy(line, *back_up, place + 2);
	free(*back_up);
	*back_up = new_back_up;
	return (&line[0]);
}

char	*last(char **back_up)
{
	char	*line;

	line = ft_strdup(*back_up);
	if (!line || ft_strlen(line) == 0)
	{
		free(*back_up);
		free(line);
		*back_up = NULL;
		return (NULL);
	}
	free(*back_up);
	*back_up = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*fd_table[OPEN_MAX] = {0, };
	int			place;
	int			read_val;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		place = find_nl(fd_table[fd]);
		if (place >= 0)
			return (nl_inline(&fd_table[fd], place));
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val <= 0)
			break ;
		buf[read_val] = '\0';
		fd_table[fd] = ft_strjoin(fd_table[fd], &buf[0]);
		if (!fd_table[fd])
			return (NULL);
	}
	return (last(&fd_table[fd]));
}
