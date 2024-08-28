/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:35:26 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:36:06 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*create_substring(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !*str)
		return (free(str), NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (*(str + i) == '\n')
	{
		i++;
		new_str = (char *)malloc((ft_strlen(str) - i) + 1);
		if (!new_str)
			return (free(str), NULL);
		while (*(str + i))
			*(new_str + j++) = *(str + i++);
		*(new_str + j) = '\0';
		if (last_char(new_str) == '\t')
			return (free(str), free(new_str), NULL);
		free(str);
		return (new_str);
	}
	return (free(str), NULL);
}

static char	*read_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	while (*(str + i) && *(str + i) != '\n' && *(str + i) != '\t')
		i++;
	if (*(str + i) == '\t')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (free(str), NULL);
	i = 0;
	while (*(str + i) && *(str + i) != '\n' && *(str + i) != '\t')
	{
		*(line + i) = *(str + i);
		i++;
	}
	if (*(str + i) == '\t')
	{
		*(line + i) = *(str + i);
		i++;
	}
	return (*(line + i) = '\0', line);
}

int	check_malloc(int fd, char *read_buffer, char **read_content)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (free(read_buffer), 0);
	*read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!*read_content)
		return (free(read_buffer), read_buffer = NULL, 0);
	return (1);
}

char	*continue_gnl(char **buffer)
{
	char	*reader;

	reader = read_line(*buffer);
	if (!reader)
		return (NULL);
	*buffer = create_substring(*buffer);
	if (!*buffer && reader && !(last_char(reader) == '\t'))
		return (free(reader), NULL);
	return (reader);
}

char	*get_next_line(int fd)
{
	char		*reader;
	int			n;
	static char	*buffer;

	if (!check_malloc(fd, buffer, &reader))
		return (NULL);
	n = -1;
	while (!(ft_strchr(buffer, '\n')) && n && (buffer || n == -1))
	{
		n = read(fd, reader, BUFFER_SIZE);
		if (n == -1)
			return (free(reader), free_this(buffer), NULL);
		*(reader + n) = '\0';
		if (!n)
			buffer = ft_strjoin(buffer, "\t");
		else
			buffer = ft_strjoin(buffer, reader);
	}
	free(reader);
	return (continue_gnl(&buffer));
}
