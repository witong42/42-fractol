/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:10:05 by witong            #+#    #+#             */
/*   Updated: 2024/09/24 12:44:26 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# define ERROR_MSG "Incorrect inputs, Please enter\n\t \
./fractol mandelbrot\n\tor\n\t./fractol julia <value1> <value2>\n \
Pretty Julia sets:\n\t \
./fractol julia -0.7269 0.1889\n\t \
./fractol julia 0.285 0.01\n\t \
./fractol julia -0.70176 -0.3842\n\t \
./fractol julia -0.835 -0.2321\n\t \
./fractol julia 0.37 0.1\n\t"

# define SIZE 800
/* For practical purpose we want the window to be squared,
so we use SIZE instead of HEIGHT and WIDTH. */

// hooks codes
# define ESC			65307
# define UP				65362
# define DOWN			65364
# define LEFT			65361
# define RIGHT			65363
# define R				114
# define C				99
# define P				112
# define M				109
# define SCROLL_UP		4
# define SCROLL_DOWN	5

// structs
typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;
	char	*pxl_img;
	int		bpp;
	int		size_line;
	int		endian;
	double	shift_x;
	double	shift_y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	int		color;
	int		max_iterations;
}		t_fractal;

// utils.c
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
int		is_double(const char *str);
double	ft_atof(const char *str);

//clean.c
void	free_fract(t_fractal *fract);
int		failure_close(t_fractal *fract);
int		success_close(t_fractal *fract);

// init.c
void	ft_fract_init(t_fractal *fract);
void	ft_mlx_init(t_fractal *fract);

// render.c
void	fract_render(t_fractal *fract);

// events.c
int		key_events(int keycode, t_fractal *fract);
int		mouse_events(int button, int x, int y, t_fractal *fract);

#endif
