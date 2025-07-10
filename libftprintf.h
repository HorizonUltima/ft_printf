/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:17 by hgergink          #+#    #+#             */
/*   Updated: 2025/07/10 16:03:15 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define HEXB "0123456789ABCDEF"
# define HEXL "0123456789abcdef"

void	ft_chrprint_iter(char c, int *count);
void	ft_numprint_iter(long long int num, int *count);
void	ft_strprint_iter(char *str, int *count);
void	ft_hexprint_iter(unsigned int num, int *count, char *base);
void	ft_ptrprint_iter(unsigned long int ptradr, int *count);
int		ft_printf(const char *str, ...);

#endif
