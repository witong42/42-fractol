/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:01:34 by witong            #+#    #+#             */
/*   Updated: 2024/09/23 07:00:34 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Validates the command-line arguments
static int	validate_args(int ac, char **av)
{
	if ((ac == 2 && (ft_strcmp(av[1], "julia") != 0
				&& ft_strcmp(av[1], "mandelbrot") != 0))
		|| (ac == 4 && ft_strcmp(av[1], "julia") != 0)
		|| (ac != 2 && ac != 4))
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (0);
	}
	return (1);
}

// Main function to initialize and run the fractal program
int	main(int ac, char **av)
{
	t_fractal	*fract;

	if (!validate_args(ac, av))
		return (0);
	fract = malloc(sizeof(t_fractal));
	if (!fract)
		failure_close(fract);
	ft_fract_init(fract);
	fract->name = av[1];
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0
		&& is_double(av[2]) && is_double(av[3]))
	{
		fract->cx = ft_atof(av[2]);
		fract->cy = ft_atof(av[3]);
	}
	ft_mlx_init(fract);
	fract_render(fract);
	mlx_key_hook(fract->win, key_events, fract);
	mlx_mouse_hook(fract->win, mouse_events, fract);
	mlx_hook(fract->win, 17, 0, success_close, fract);
	mlx_loop(fract->mlx);
	failure_close(fract);
}
