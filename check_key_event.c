/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:45:05 by ski               #+#    #+#             */
/*   Updated: 2022/01/23 12:45:07 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/* ************************************************************************** */
int check_key_event(int key, void *param)
{
	t_data *data;
	t_point p0 = {.x = 10, .y = 100};
	t_point p1 = {.x = 100, .y = 20};
	t_point p2 = {.x = 90, .y = 90};
	t_point p3 = {.x = 100, .y = 100};
	// t_point p4 = {.x = 100, .y = 200};
	
	data = (t_data *)param;
	
	ft_printf("%d\n", key);

	
	if (key == KEY_D)
	{
		// plot_line(p0, p1, data);
		ski_line(p0, p1, data, );
		ft_printf("D was hit\n");
	}
	if (key == KEY_F)
	{
		// plot_line(p2, p3, data);
		ski_line(p2, p3, data);
		ft_printf("F was hit\n");
	}

	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}

	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx, data->win);
	}

	return 0;
}

