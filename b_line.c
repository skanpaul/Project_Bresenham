/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:48 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:55:50 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int bresenham(t_point start, t_point end, t_data *data, int color)
{
	int diff_x;
	int diff_y;
	int step_x;
	int step_y;
	int err;
	int e2;

	diff_x = abs(end.x - start.x);
	step_x = start.x < end.x ? 1 : -1;
	diff_y = -abs(end.y - start.y);
	step_y = start.y < end.y ? 1 : -1;
	err = diff_x + diff_y; /* error value e_xy */

	while (true) /* loop */
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x, start.y, color);

		if (start.x == end.x && start.y == end.y)
			break;
		e2 = 2 * err;
		if (e2 >= diff_y) /* e_xy+e_x > 0 */
		{
			if (start.x == end.x)
				break;
			err += diff_y;
			start.x += step_x;
		}

		if (e2 <= diff_x) /* e_xy+e_y < 0 */
		{
			if (start.y == end.y)
				break;
			err += diff_x;
			start.y += step_y;
		}
	}
	return (0);
}
