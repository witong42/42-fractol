/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:07 by witong            #+#    #+#             */
/*   Updated: 2024/09/25 10:28:19 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Maps pixel coordinates to fractal coordinates
static void	mapping(t_fractal *fract, int x, int y)
{
	fract->zx = ((4.0 * x / SIZE - 2.0) * fract->zoom) + fract->shift_x;
	fract->zy = ((4.0 * y / SIZE - 2.0) * fract->zoom) + fract->shift_y;
}

// Sets the initial values for cx and cy based on the fractal type
static void	fract_switch(t_fractal *fract)
{
	if (ft_strcmp(fract->name, "mandelbrot") == 0)
	{
		fract->cx = fract->zx;
		fract->cy = fract->zy;
	}
}

// Calculates the color of a pixel based on the fractal iteration
static int	calculate(t_fractal *fract, int x, int y)
{
	int		i;
	double	tmp;

	mapping(fract, x, y);
	fract_switch(fract);
	i = 0;
	while (i < fract->max_iterations)
	{
		tmp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy + fract->cx;
		fract->zy = 2 * tmp * fract->zy + fract->cy;
		if (fract->zx * fract->zx + fract->zy * fract->zy > 4)
			break ;
		i++;
	}
	if (i == fract->max_iterations)
		return (0x000000);
	else
		return (fract->color * (i % 255));
}

// Sets the color of a pixel in the image
static void	pxl_img(t_fractal *fract, int x, int y)
{
	int		color;
	char	*pixel;

	color = calculate(fract, x, y);
	pixel = fract->pxl_img + (y * fract->size_line + x * (fract->bpp / 8));
	*(unsigned int *)pixel = color;
}

// Renders the fractal image using mlx_put_image_to_window
// instead of mlx_pixel_put
void	fract_render(t_fractal *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			pxl_img(fract, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
