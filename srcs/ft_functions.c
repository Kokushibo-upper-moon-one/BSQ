/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stnineta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:29:37 by stnineta          #+#    #+#             */
/*   Updated: 2021/02/08 13:44:43 by stnineta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_err(char c)
{
	write(2, &c, 1);
}

void	error(char *err)
{
	int i;

	i = 0;
	while (err[i])
	{
		ft_putchar_err(err[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i * j);
}
