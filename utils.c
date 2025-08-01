/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:53 by hgergink          #+#    #+#             */
/*   Updated: 2025/08/01 08:31:04 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chrprint_iter(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_numprint_iter(long long int num, int *count)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		*count += 1;
	}
	if (num >= 10)
		ft_numprint_iter(num / 10, count);
	ft_chrprint_iter((char)(num % 10 + 48), count);
}

void	ft_strprint_iter(char *str, int *count)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		*count += 1;
		str++;
	}
}

void	ft_hexprint_iter(unsigned int num, int *count, char *base)
{
	if (num >= 16)
		ft_hexprint_iter(num / 16, count, base);
	ft_chrprint_iter(base[num % 16], count);
}

void	ft_ptrprint_iter(unsigned long int ptradr, int *count)
{
	if (ptradr >= 16)
		ft_ptrprint_iter(ptradr / 16, count);
	ft_chrprint_iter(HEXL[ptradr % 16], count);
}
