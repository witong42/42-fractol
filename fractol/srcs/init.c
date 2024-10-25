/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:37:48 by witong            #+#    #+#             */
/*   Updated: 2024/09/23 07:03:25 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initializes fractal parameters
void	ft_fract_init(t_fractal *fract)
{
	fract->zoom = 1.0;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->cx = -0.7;
	fract->cy = 0.27015;
	fract->max_iterations = 42;
	fract->color = 0x241212;
}

// Initializes the MLX library and creates a window and image
void	ft_mlx_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		failure_close(fract);
	fract->win = mlx_new_window(fract->mlx, SIZE, SIZE, fract->name);
	if (!fract->win)
		failure_close(fract);
	fract->img = mlx_new_image(fract->mlx, SIZE, SIZE);
	if (!fract->img)
		failure_close(fract);
	fract->pxl_img = mlx_get_data_addr(fract->img,
			&fract->bpp,
			&fract->size_line,
			&fract->endian);
	if (!fract->pxl_img)
		failure_close(fract);
}
