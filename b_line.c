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

int b_line_03(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;
	int diff_x;
	int diff_y;
	int decision;

	x = start.x;
	y = start.y;
	diff_x = end.x - start.x;
	diff_y = end.y - start.y;
	decision = 2 * diff_y + diff_x;

	while (x <= end.x)
	{
		if (is_screen_overflow(x, y))
			return (0);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

		x += 1;
		if (decision < 0)
		{
			decision = decision + 2 * diff_y;
			y += 0;
		}
		else
		{
			decision = decision + 2 * diff_y - 2 * diff_x;
			y += 1;
		}
	}

	return (0);
}
