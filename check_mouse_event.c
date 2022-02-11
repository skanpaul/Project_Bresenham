/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:44:52 by ski               #+#    #+#             */
/*   Updated: 2022/01/23 12:44:57 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/* ************************************************************************** */
int	check_mouse_event(int button,int x,int y,void *param)
{
	t_data *data;
	static int memory = 0;

	data = (t_data *)param;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x00ffffff, "Sorakann Ki");

	ft_printf("button: %d\nx: %d\ny: %d\n", button, x, y);

	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00ffff00);

	return (0);
}
