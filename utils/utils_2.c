/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:43:05 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:43:36 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	last_char(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (!i)
		return (s[i]);
	return (s[--i]);
}

void	free_close_exit(char **map, char *s, int fd, char *err_msg)
{
	unsigned long	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
	if (s)
		free(s);
	if (fd)
		close(fd);
	if (err_msg)
		write(2, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

int	count_close_fd(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = NULL;
	while (last_char(line) != '\t')
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			return (free_close_exit(NULL, NULL, fd, "Invalid Map!\n"), 0);
		count++;
	}
	free(line);
	if (close(fd) == -1)
		free_close_exit(NULL, NULL, 0, "close:");
	return (count);
}

void	set_data(t_data *data, char **argv)
{
	int i = -1;
	while (++i < 5)
		data->textures[i] = NULL;
	data->mystery = 0;
	data->moves = 0;
	data->map = create_map(0, argv[1]);
	if (!data->map || !check_map(data))
		free_close_exit(data->map, NULL, 0, "Invalid Map.\n");
}

int	on_destroy(t_data *data)
{
	int	i;

	i = -1;
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
		{
			while (++i < 5)
			{
				if (data->textures[i])
					mlx_destroy_image(data->mlx_ptr, data->textures[i]);
			}
			// if (data->img.img_ptr)
			// 	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_close_exit(data->map, NULL, 0, "Exited successfully!\n");
	return (1);
}
