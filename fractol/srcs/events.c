/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:37:43 by witong            #+#    #+#             */
/*   Updated: 2024/09/25 10:28:15 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Initializes the MLX library and creates a window and image
int (*f)(int keycode, void *param) */
int	key_events(int keycode, t_fractal *fract)
{
	if (keycode == ESC)
		success_close(fract);
	if (keycode == UP)
		fract->shift_y -= 0.05 * fract->zoom;
	if (keycode == DOWN)
		fract->shift_y += 0.05 * fract->zoom;
	if (keycode == LEFT)
		fract->shift_x -= 0.05 * fract->zoom;
	if (keycode == RIGHT)
		fract->shift_x += 0.05 * fract->zoom;
	if (keycode == C)
		fract->color += 0x121314;
	if (keycode == P)
		fract->max_iterations += 10;
	if (keycode == M)
		fract->max_iterations -= 10;
	if (keycode == R)
		ft_fract_init(fract);
	fract_render(fract);
	return (0);
}

/* Handles mouse events for fractal zooming
int (*f)(int button, int x, int y, void *param) */
int	mouse_events(int button, int x, int y, t_fractal *fract)
{
	double	zoom_factor;

	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		zoom_factor = 1.05;
	else if (button == SCROLL_DOWN)
		zoom_factor = 0.95;
	else
		return (0);
	fract->zoom *= zoom_factor;
	fract_render(fract);
	return (0);
}
