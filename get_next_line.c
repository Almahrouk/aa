/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dal-mahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:06:07 by dal-mahr          #+#    #+#             */
/*   Updated: 2024/11/16 12:06:12 by dal-mahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*keep_rest(char *temp, int start)
{
	char	*rest;
	int		len;

	len = ft_strlen(temp) - start;
	if (len <= 0)
	{
		free(temp);
		return (NULL);
	}
	rest = ft_substr(temp, start, len);
	free(temp);
	return (rest);
}

static char	*extract_line(char *temp, int *start_next)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		*start_next = i + 1;
	else
	{
		*start_next = i;
		if (i == 0 && temp[i] == '\0')
			return (NULL);
	}
	line = ft_substr(temp, 0, *start_next);
	return (line);
}

static char	*new_line(int fd, char *temp, char *buffer)
{
	int		read_bytes;
	char	*new_temp;

	while (!ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((read_bytes == 0 && temp[0] == '\0') || (read_bytes == -1))
		{
			free(temp);
			return (NULL);
		}
		if (read_bytes == 0)
			return (temp);
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin(temp, buffer);
		free(temp);
		temp = new_temp;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;
	char		*buffer;
	int			start_next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (temp == NULL)
		temp = ft_strdup("");
	temp = new_line(fd, temp, buffer);
	free(buffer);
	if (!temp)
		return (NULL);
	line = extract_line(temp, &start_next);
	temp = keep_rest(temp, start_next);
	return (line);
}
