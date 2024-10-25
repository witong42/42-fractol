/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:35:52 by witong            #+#    #+#             */
/*   Updated: 2024/09/19 04:36:39 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_fract(t_fractal *fract)
{
	if (fract)
	{
		if (fract->img)
			mlx_destroy_image(fract->mlx, fract->img);
		if (fract->win)
			mlx_destroy_window(fract->mlx, fract->win);
		if (fract->mlx)
		{
			mlx_destroy_display(fract->mlx);
			free(fract->mlx);
		}
		free(fract);
	}
}

int	failure_close(t_fractal *fract)
{
	free_fract(fract);
	exit(EXIT_FAILURE);
	return (0);
}

int	success_close(t_fractal *fract)
{
	free_fract(fract);
	exit(EXIT_SUCCESS);
	return (0);
}
