/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:40:40 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:41:20 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_elem(t_point *coord, t_data data, char c, int alrdy)
{
	int	i;
	int	j;
	int	count;

	count = data.mystery - alrdy;
	if (alrdy == -1)
		count = 0;
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == c && count == 0)
			{
				(*coord).y = i;
				(*coord).x = j;
				return ;
			}
			else if (data.map[i][j] == c)
				count--;
			j++;
		}
		i++;
	}
}

void	move_up(t_data *data)
{
	t_point	coord;

	find_elem(&coord, *data, 'P', -1);
	if (data->map[coord.y - 1][coord.x] == '1')
		return ;
	else if (data->map[coord.y - 1][coord.x] == 'E' && data->mystery)
		return ;
	else if (data->map[coord.y - 1][coord.x] == 'E')
	{
		write(1, "MOVES: ", 7);
		ft_putnbr(++data->moves);
		write(1, "\n", 1);
		on_destroy(data);
	}
	else
	{
		if (data->map[coord.y - 1][coord.x] == 'C')
			data->mystery--;
		data->map[coord.y][coord.x] = '0';
		data->map[coord.y - 1][coord.x] = 'P';
		data->moves++;
		render_map(data);
	}
}

void	move_left(t_data *data)
{
	t_point	coord;

	find_elem(&coord, *data, 'P', -1);
	if (data->map[coord.y][coord.x - 1] == '1')
		return ;
	else if (data->map[coord.y][coord.x - 1] == 'E' && data->mystery)
		return ;
	else if (data->map[coord.y][coord.x - 1] == 'E')
	{
		write(1, "MOVES: ", 7);
		ft_putnbr(++data->moves);
		write(1, "\n", 1);
		on_destroy(data);
	}
	else
	{
		if (data->map[coord.y][coord.x - 1] == 'C')
			data->mystery--;
		data->map[coord.y][coord.x] = '0';
		data->map[coord.y][coord.x - 1] = 'P';
		data->moves++;
		render_map(data);
	}
}

void	move_down(t_data *data)
{
	t_point	coord;

	find_elem(&coord, *data, 'P', -1);
	if (data->map[coord.y + 1][coord.x] == '1')
		return ;
	else if (data->map[coord.y + 1][coord.x] == 'E' && data->mystery)
		return ;
	else if (data->map[coord.y + 1][coord.x] == 'E')
	{
		write(1, "MOVES: ", 7);
		ft_putnbr(++data->moves);
		write(1, "\n", 1);
		on_destroy(data);
	}
	else
	{
		if (data->map[coord.y + 1][coord.x] == 'C')
			data->mystery--;
		data->map[coord.y][coord.x] = '0';
		data->map[coord.y + 1][coord.x] = 'P';
		data->moves++;
		render_map(data);
	}
}

void	move_right(t_data *data)
{
	t_point	coord;

	find_elem(&coord, *data, 'P', -1);
	if ((data)->map[coord.y][coord.x + 1] == '1')
		return ;
	else if ((data)->map[coord.y][coord.x + 1] == 'E' && (data)->mystery)
		return ;
	else if ((data)->map[coord.y][coord.x + 1] == 'E')
	{
		write(1, "MOVES: ", 7);
		ft_putnbr(++data->moves);
		write(1, "\n", 1);
		on_destroy(data);
	}
	else
	{
		if ((data)->map[coord.y][coord.x + 1] == 'C')
			(data)->mystery--;
		(*data).map[coord.y][coord.x] = '0';
		(*data).map[coord.y][coord.x + 1] = 'P';
		data->moves++;
		render_map(data);
	}
}
