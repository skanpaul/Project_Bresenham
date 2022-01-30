/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:01:26 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:01:28 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int key_press(int key, void *param)
{
	static int count = 1;
	t_point p_temp = {.x = 0, .y = 0};
	t_data *data;

	t_point centre = {.x = 200, .y = 200};

	t_point p1 = {.x = centre.x + 100, .y = centre.y + 0 };		// 0 degre
	t_point p2 = {.x = centre.x + 100, .y = centre.y + 50 };	// 22.5 degree
	t_point p3 = {.x = centre.x + 100, .y = centre.y + 100 };	// 45 degree
	t_point p4 = {.x = centre.x + 50,  .y = centre.y + 100 };	// 77.5 degree
	t_point p5 = {.x = centre.x + 0,   .y = centre.y + 100 };	// 90 degree
	t_point p6 = {.x = centre.x - 50,  .y = centre.y + 100 };	// 112.5 degree
	t_point p7 = {.x = centre.x - 100, .y = centre.y + 100 };	// 135 degree
	t_point p8 = {.x = centre.x - 100,  .y = centre.y + 50 };	// 157.5 degree
	t_point p9 = {.x = centre.x - 100,  .y = centre.y + 0  };	// 180 degree

	data = (t_data *)param;


	if (key == KEY_F) 
	{
		if (count == 1)			p_temp = p1;
		else if (count == 2)	p_temp = p2;		
		else if (count == 3)	p_temp = p3;
		else if (count == 4)	p_temp = p4;
		else if (count == 5)	p_temp = p5;
		else if (count == 6)	p_temp = p6;
		else if (count == 7) 	
			p_temp = p7;
		else if (count == 8)	p_temp = p8;
		else if (count == 9)	p_temp = p9;
		else
			count = 1;

		bresenham(centre, p_temp, data, COLOR_RED);
		count++;
	}
	/* ----------------------------------------------------- */
	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_grid(100, data, COLOR_BLUE);
		count = 1;
	}
	/* ----------------------------------------------------- */
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	/* ----------------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
	// if (key == KEY_A) b_line_03(centre, p1, data, COLOR_RED);
	// if (key == KEY_S) b_line_03(centre, p2, data, COLOR_GREEN);
	// if (key == KEY_D) b_line_03(centre, p3, data, COLOR_GREEN);
	// if (key == KEY_F) b_line_03(centre, p4, data, COLOR_RED);
	// if (key == KEY_G) b_line_03(centre, p5, data, COLOR_GREEN);
	// if (key == KEY_H) b_line_03(centre, p6, data, COLOR_RED);
	// if (key == KEY_J) b_line_03(centre, p7, data, COLOR_GREEN);
	// if (key == KEY_K) b_line_03(centre, p8, data, COLOR_RED);
	// if (key == KEY_L) b_line_03(centre, p9, data, COLOR_GREEN);