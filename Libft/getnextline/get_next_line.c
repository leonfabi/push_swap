/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:00 by fkrug             #+#    #+#             */
/*   Updated: 2023/05/10 16:01:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*shift_stat_buffer(char *buffer, char *tmp_buf, ssize_t c)
{
	ssize_t	shift;

	shift = -1;
	while (tmp_buf[++shift])
		buffer[shift] = tmp_buf[shift];
	shift = -1;
	while (buffer[++shift])
	{
		if ((c + shift) > BUFFER_SIZE)
			buffer[shift] = '\0';
		else
			buffer[shift] = tmp_buf[shift + c];
	}
	return (buffer);
}

static char	*allocate(ssize_t c, char *buffer, char *tmp_buf, ssize_t siz)
{
	char	*nl;

	nl = (char *) malloc(sizeof(char) * (siz + 1 + c));
	if (nl == NULL)
		return (NULL);
	nl[siz + c] = '\0';
	shift_stat_buffer(buffer, tmp_buf, c);
	return (nl);
}

static char	*get_newline(int fd, char *buffer, ssize_t size)
{
	ssize_t		sz;
	ssize_t		c;
	char		tmp_buf[BUFFER_SIZE + 1];
	char		*nl;

	c = 0;
	sz = read_fd(fd, tmp_buf, buffer);
	while (tmp_buf[c] != '\0' && tmp_buf[c] != '\n' && sz > 0)
		c++;
	if (tmp_buf[c] != '\n' && sz > 0)
		nl = get_newline(fd, buffer, size + c);
	else if ((size == 0 && sz == 0) || sz == -1)
		return (NULL);
	else
	{
		if (tmp_buf[c] == '\n')
			c++;
		nl = allocate(c, buffer, tmp_buf, size);
	}
	if (nl == NULL)
		return (NULL);
	while (--c >= 0)
		nl[size + c] = tmp_buf[c];
	return (nl);
}

static char	*get_newline_from_buffer(char *buffer, ssize_t id)
{
	ssize_t	c_id;
	char	*nl;

	c_id = id + 1;
	(id)++;
	nl = (char *)malloc(id * sizeof(char) + 1);
	if (nl == NULL)
		return (NULL);
	nl[c_id] = '\0';
	while (--c_id >= 0)
		nl[c_id] = buffer[c_id];
	shift_stat_buffer(buffer, buffer, id);
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		tmp_buf[BUFFER_SIZE + 1];
	ssize_t		id;
	char		*nl;

	id = -1;
	while (++id <= BUFFER_SIZE && (fd > -1 && fd < 1024))
		tmp_buf[id] = buffer[fd][id];
	id = 0;
	nl = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	while (buffer[fd][id] != '\0' && buffer[fd][id] != '\n')
		id++;
	if (buffer[fd][id] == '\n')
		return (get_newline_from_buffer(buffer[fd], id));
	else
	{
		nl = get_newline(fd, buffer[fd], id);
		while (--id >= 0 && nl != NULL)
			nl[id] = tmp_buf[id];
		return (nl);
	}
	return (0);
}
