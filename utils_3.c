/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:00:36 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:01:32 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map_continue(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures[2], j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures[3], j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->textures[4], j * TILE_SIZE, i * TILE_SIZE);
}

void	render_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < count_this_2(data->map))
	{
		j = -1;
		while (++j < count_this(data->map[0]))
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[0], j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[1], j * TILE_SIZE, i * TILE_SIZE);
			else
				render_map_continue(data, i, j);
		}
	}
}

void	map_map(t_data *data)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			ME, &tile_size, &tile_size);
	if (!(data->textures[0]))
		on_destroy(data);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			EMPTY, &tile_size, &tile_size);
	if (!(data->textures[1]))
		on_destroy(data);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			WALL, &tile_size, &tile_size);
	if (!(data->textures[2]))
		on_destroy(data);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			MYSTERY, &tile_size, &tile_size);
	if (!(data->textures[3]))
		on_destroy(data);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			EXIT, &tile_size, &tile_size);
	if (!(data->textures[4]))
		on_destroy(data);
}

void	main_continue(t_data *data)
{
	// data->img.img_pixels_ptr = (int *)mlx_get_data_addr(data->img.img_ptr,
	// 		&(data->img.bits_pp), &(data->img.line_len), &(data->img.endian));
	// if (!(data->img.img_pixels_ptr))
	// 	on_destroy(data);
	render_map(data);
	mlx_key_hook(data->win_ptr, &on_key_press, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		set_data(&data, argv);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (on_destroy(&data), 1);
		data.win_ptr = mlx_new_window(data.mlx_ptr,
				count_this(data.map[0]) * TILE_SIZE,
				count_this_2(data.map) * TILE_SIZE, "so_long");
		if (!data.win_ptr)
			return (on_destroy(&data), 1);
		map_map(&data);
		// data.img.img_ptr = mlx_new_image(data.mlx_ptr,
		// 		count_this(data.map[0]) * TILE_SIZE,
		// 		count_this_2(data.map) * TILE_SIZE);
		// if (!data.img.img_ptr)
		// 	return (on_destroy(&data), 1);
		main_continue(&data);
	}
	return (0);
}
int	on_key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		move_up(data);
	else if (keysym == XK_a)
		move_left(data);
	else if (keysym == XK_s)
		move_down(data);
	else if (keysym == XK_d)
		move_right(data);
	else if (keysym == XK_Escape)
		on_destroy(data);
	write(1, "MOVES: ", 7);
	return (ft_putnbr((*data).moves), write(1, "\n", 1), 1);
}