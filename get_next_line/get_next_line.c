/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/22 18:16:50 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Returns char pointer passed to it after appending what is read up until
the next line skip (\n), freeing the auxiliary char pointer used
*/
char	*ft_read(int fd, char *buffer)
{
	char	*aux;
	int		read_return;

	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (aux == NULL)
		return (0);
	read_return = -1;
	while (!ft_strchr(buffer, '\n') && read_return != 0)
	{
		read_return = read(fd, aux, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[read_return] = '\0';
		buffer = ft_strjoin(buffer, aux);
	}
	free(aux);
	return (buffer);
}

/*
Returns char pointer corresponding to the next line in the file. Copies
from the buffer to an auxiliary pointer up to a line skip, which is returned.
*/
char	*ft_line(char *buffer)
{
	char	*aux;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	aux = malloc((i + 2) * sizeof(char));
	if (aux == NULL)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		aux[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		aux[i] = buffer[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

/*
Returns an auxiliary char pointer which stores everything after the
line skip (\n), serving as an overflow management.
*/
char	*ft_overflow(char *buffer)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	aux = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	i++;
	while (buffer[i])
	{
		aux[j++] = buffer[i++];
	}
	aux[j] = '\0';
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	next_line = ft_line(buffer);
	buffer = ft_overflow(buffer);
	return (next_line);
}
