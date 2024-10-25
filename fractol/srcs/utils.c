/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:05:50 by witong            #+#    #+#             */
/*   Updated: 2024/09/20 13:06:35 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	is_double(const char *str)
{
	int	has_decimal;
	int	has_digit;

	has_decimal = 0;
	has_digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (*str >= '0' && *str <= '9')
			has_digit = 1;
		else
			return (0);
		str++;
	}
	return (has_digit);
}

static double	parse_fraction(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fraction += (**str - '0') / divisor;
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	result = 0.0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	fraction = parse_fraction(&str);
	return (sign * (result + fraction));
}
