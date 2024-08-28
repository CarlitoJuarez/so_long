/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:32:58 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:33:42 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_this(char *file, char **map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open:");
		return (free_close_exit(map, NULL, 0, NULL), 0);
	}
	return (fd);
}

char	**open_malloc_close(int *count, char *file)
{
	int		fd;
	char	**map;

	map = NULL;
	check_file(file);
	fd = open_this(file, NULL);
	*count = count_close_fd(fd);
	if (!*count)
		return (NULL);
	map = malloc(sizeof(char *) * (*count + 1));
	if (!map)
		free_close_exit(NULL, NULL, 0, "MALLOC FAIL!\n");
	map[*count] = 0;
	return (map);
}

char	*read_line_t(char *s)
{
	int		i;
	char	*new;

	i = 0;
	while (s && s[i] && s[i] != '\t')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (free(s), NULL);
	new[i] = 0;
	i = 0;
	while (s && s[i] && s[i] != '\t')
	{
		new[i] = s[i];
		i++;
	}
	free(s);
	return (new);
}

char	**create_map_continue(int fd, char ***map)
{
	int		i;
	char	*line;

	i = -1;
	line = NULL;
	while (!++i || line)
	{
		line = get_next_line(fd);
		if (!line)
			free_close_exit(*map, NULL, fd, "GNL FAIL!\n");
		if (last_char(line) == '\t')
		{
			(*map)[i] = read_line_t(line);
			if (!(*map)[i])
				free_close_exit(*map, NULL, fd, "GNL FAIL!\n");
			if (close(fd) == -1)
				free_close_exit(*map, NULL, 0, "close: \n");
			return (*map);
		}
		(*map)[i] = line;
	}
	return (*map);
}

char	**create_map(int fd, char *file)
{
	char	**map;
	int		count;

	map = open_malloc_close(&count, file);
	fd = open_this(file, map);
	if (!map)
		return (NULL);
	return (create_map_continue(fd, &map));
}
