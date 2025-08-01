/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:14:23 by hgergink          #+#    #+#             */
/*   Updated: 2025/08/01 08:59:17 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ptrcheck(void *ptr, int *count)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write(1, "0x", 2);
	*count += 2;
	ft_ptrprint_iter((unsigned long int)ptr, count);
}

static int	ft_formatcheck(char chr, va_list *args, int *count)
{
	if (chr == 'c')
		ft_chrprint_iter(va_arg(*args, int), count);
	else if (chr == 's')
		ft_strprint_iter(va_arg(*args, char *), count);
	else if (chr == 'd' || chr == 'i')
		ft_numprint_iter(va_arg(*args, int), count);
	else if (chr == 'u')
		ft_numprint_iter(va_arg(*args, unsigned int), count);
	else if (chr == 'p')
		ft_ptrcheck(va_arg(*args, void *), count);
	else if (chr == 'x')
		ft_hexprint_iter(va_arg(*args, unsigned int), count, HEXL);
	else if (chr == 'X')
		ft_hexprint_iter(va_arg(*args, unsigned int), count, HEXB);
	else
		return (0);
	return (1);
}

static void	ft_gateway(const char **str, va_list *args, int *count)
{
	if (ft_formatcheck(*(*str + 1), args, count))
	{
		(*str)++;
	}
	else if (*(*str + 1) == '%')
	{
		(*str)++;
		write(1, *str, 1);
		*count += 1;
	}
	else
	{
		write(1, "%", 1);
		*count += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_gateway(&str, &args, &count);
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
