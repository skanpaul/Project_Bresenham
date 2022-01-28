/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:48 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:55:50 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int bidon(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;
	float m;


	m = 2;
	x = start.x;
	y = start.y;

	(void)end.y;

	while (x <= end.x)
	{
		y = m * x;		
		if (is_screen_overflow(x, y))
			break;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		printf("PRINTED with:\n- x: %d\n- y: %d\n", x, y);
		x++;
	}
	printf("END with:\n- x: %d\n- y: %d\n", x, y);

	return (0);
}
