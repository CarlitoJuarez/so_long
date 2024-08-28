/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:31:50 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:32:41 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
		free_close_exit(NULL, NULL, 0, "Bad Extension\n");
	else if (file[i - 4] == '.' && (file[i - 5] < 33
			|| file[i - 5] > 126 || file[i - 5] == '/'))
		free_close_exit(NULL, NULL, 0, "Bad Filename\n");
	i -= 4;
	if (i == 0)
		free_close_exit(NULL, NULL, 0, "Bad Filename\n");
	while (--i)
	{
		if (file[i] < 33 || file[i] > 126)
			free_close_exit(NULL, NULL, 0, "Bad Filename\n");
	}
}

int	check_count(t_data *data, char **map)
{
	int	i;
	int	j;
	int	player_exit;

	i = -1;
	player_exit = 0;
	if (!map)
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i] && map[i][++j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				player_exit++;
			else if (map[i][j] == 'C')
				data->mystery++;
			else if (!(map[i][j] != '1' || map[i][j] != '0'))
				return (0);
		}
	}
	if (player_exit != 2 || !data->mystery)
		return (0);
	return (1);
}

int	shape(char **map)
{
	int	rows;
	int	columns;
	int	test;

	test = 0;
	rows = 0;
	while (map[rows])
	{
		if (rows == 0)
		{
			columns = 0;
			while (map[rows][columns] && map[rows][columns] != '\n')
				columns++;
		}
		else
		{
			test = 0;
			while (map[rows][test] && map[rows][test] != '\n')
				test++;
			if (test != columns)
				return (0);
		}
		rows++;
	}
	return (1);
}

int	wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map[i][j] == 'C' || map[i][j] == 'P'
				|| map[i][j] == 'E' || map[i][j] == '1'
				|| map[i][j] == '0'))
				return (0);
			if (i == 0 || j == 0 || i == count_this_2(map) - 1
				|| j == count_this(map[i]) - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
		}
	}
	return (1);
}

int	check_map(t_data *data)
{
	if (!(check_count(data, data->map)))
		return (0);
	if (!shape(data->map))
		return (0);
	if (!wall(data->map))
		return (0);
	if (!flood_fill(*data))
		return (0);
	update_map(data->map);
	return (1);
}
