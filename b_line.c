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
static int h_line(t_point start, t_point end, t_data *data, int color);
static int v_line(t_point start, t_point end, t_data *data, int color);
static int b_line_fct_x(t_point start, t_point end, t_data *data, int color);
static int b_line_fct_y(t_point start, t_point end, t_data *data, int color);

/* ************************************************************************** */
int b_line_03(t_point start, t_point end, t_data *data, int color)
{
	int diff_x;
	int diff_y;

	diff_x = abs(end.x - start.x);
	diff_y = abs(end.y - start.y);
	/* -------------------------------------------- */
	if (diff_y == 0)
	{
		printf("m = ZERO\n");
		h_line(start, end, data, color);
		return (0);
	}
	/* -------------------------------------------- */
	if (diff_x == 0)
	{
		printf("m = INFINI\n");
		v_line(start, end, data, color);
		return (0);
	}
	/* si M <= 1 ----------------------------------- */

	if (diff_y - diff_x <= 0)
	{
		printf("m plus PETIT ou EGAL à 1\n");
		b_line_fct_x(start, end, data, color);
		return (0);
	}
	/* si M > 1-------------------------------------------- */
	else
	{
		printf("m plus GRAND à 1\n");
		b_line_fct_y(start, end, data, color);
		return (0);
	}

	return (0);
}
/* ************************************************************************** */
static int b_line_fct_x(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;
	int decision;
	int x_inc;
	int y_inc;
	int diff_x;
	int diff_y;

	x = start.x;
	y = start.y;
	diff_x = abs(end.x - start.x);
	diff_y = abs(end.y - start.y);

	x_inc = 1;
	y_inc = 1;

	if (start.x > end.x)
		x_inc = -1;
	if (start.y > end.y)
		y_inc = -1;

	decision = 2 * diff_y + diff_x;

	while (x <= end.x)
	{
		if (is_screen_overflow(x, y))
			return (0);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

		x += x_inc;
		/* -------------------------------------------- */
		if (decision < 0)
			decision = decision + 2 * diff_y;
		/* -------------------------------------------- */
		else
		{
			decision = decision + 2 * diff_y - 2 * diff_x;
			y += y_inc;
		}
		/* -------------------------------------------- */
	}
	return (0);
}

/* ************************************************************************** */
static int b_line_fct_y(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;
	int decision;
	int x_inc;
	int y_inc;
	int diff_x;
	int diff_y;

	x = start.x;
	y = start.y;
	diff_x = abs(end.x - start.x);
	diff_y = abs(end.y - start.y);

	x_inc = 1;
	y_inc = 1;
	if (start.x > end.x)
		x_inc = -1;
	if (start.y > end.y)
		y_inc = -1;

	decision = 2 * diff_x + diff_y;
	while (y <= end.y)
	{
		if (is_screen_overflow(x, y))
			return (0);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

		y += y_inc;
		/* -------------------------------------------- */
		if (decision < 0)
			decision = decision + 2 * diff_x;
		/* -------------------------------------------- */
		else
		{
			decision = decision + 2 * diff_x - 2 * diff_y;
			x += x_inc;
		}
		/* -------------------------------------------- */
	}
	return (0);
}

/* ************************************************************************** */
static int h_line(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;

	x = start.x;
	y = start.y;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

	while (x <= end.x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		x++;
	}
	return (0);
}

/* ************************************************************************** */
static int v_line(t_point start, t_point end, t_data *data, int color)
{
	int x;
	int y;

	x = start.x;
	y = start.y;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

	while (y <= end.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		y++;
	}
	return (0);
}
