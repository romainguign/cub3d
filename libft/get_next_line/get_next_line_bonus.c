/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:02:53 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 18:23:21 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_utils.h"

char	*make_line(char *line)
{
	int	len_line;

	len_line = 0;
	while (line[len_line] != '\n' && line[len_line])
		len_line++;
	if (line[len_line] == '\n')
		line[len_line + 1] = '\0';
	return (line);
}

char	*keep_end(char *line, char *buf)
{
	int	i;
	int	len_line;
	int	total_len;

	i = 0;
	len_line = 0;
	total_len = ft_strlen(line);
	while (line[len_line] != '\n' && line[len_line])
		len_line++;
	free(buf);
	buf = ft_calloc(total_len - len_line + 2, sizeof(char));
	if (!buf)
	{
		free(line);
		return (0);
	}
	if (line[len_line] == '\n')
		len_line++;
	while (line[len_line + i])
	{
		buf[i] = line[len_line + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	end_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(int fd, char *save)
{
	char	*buf;
	int		octet;

	octet = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free(save);
		return (0);
	}
	while (end_line(save) != 1 && octet > 0)
	{
		octet = read(fd, buf, BUFFER_SIZE);
		if (buf[0] == '\0' && (octet == 0 || octet == -1) && !save[0])
		{
			free(save);
			free(buf);
			return (0);
		}
		buf[octet] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!save[fd])
	{
		save[fd] = ft_calloc(1, sizeof(char));
		if (!save[fd])
			return (0);
	}
	save[fd] = get_line(fd, save[fd]);
	if (save[fd] == 0)
		return (0);
	line = ft_strjoin(line, save[fd]);
	save[fd] = keep_end(line, save[fd]);
	line = make_line(line);
	return (line);
}
