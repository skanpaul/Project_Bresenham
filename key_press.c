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
	t_data *data;

	t_point centre = {.x = 200, .y = 200};

	t_point p_droite = {.x = centre.x + 100, .y = centre.y + 0 };
	t_point q1 = {.x = centre.x + 100, .y = centre.y + 300 };

	// t_point p_bas = {.x = centre.x + 0, .y = centre.y + 100 };
	t_point q2 = {.x = centre.x + (-100), .y = centre.y + (-100) };
	// t_point c = {.x = centre.x + 0 , .y = centre.y + 100 };
	// t_point d = {.x = centre.x + 100, .y = centre.y + 0 };

	data = (t_data *)param;

	if (key == KEY_D) b_line_03(centre, p_droite, data, COLOR_WHITE);
	if (key == KEY_F) b_line_03(centre, q1, data, COLOR_GREEN);
	if (key == KEY_G) b_line_03(centre, q1, data, COLOR_RED);
	if (key == KEY_H) b_line_03(centre, q2, data, COLOR_GREEN);

	if (key == KEY_C)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_grid(50, data, COLOR_BLUE);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}

	return (0);
}









	
	// t_point origin =	{0, 0};
	// t_point p_droite =	{100, 0};
	// t_point p_gauche =	{-100, 0};
	// t_point p_haut =	{0, 100};
	// t_point p_bas =		{0, -100};
	// t_point p_q1 = {100, 100};
	// t_point p_q2 = {-100, 100};
	// t_point p_q3 = {-100, -100};
	// t_point p_q4 = {100, -100};
	// t_vector v_droite = {origin, p_droite};
	// t_vector v_gauche = {origin, p_gauche};
	// t_vector v_haut =	{origin, p_haut};
	// t_vector v_bas = 	{origin, p_bas};
	// t_vector v_q1 = {origin, p_q1};
	// t_vector v_q2 = {origin, p_q2};
	// t_vector v_q3 =	{origin, p_q3};
	// t_vector v_q4 = {origin, p_q4};

