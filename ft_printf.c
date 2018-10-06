/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:39:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 18:33:34 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

// int	ft_asprintf(char **s, const char *fmt, ...)
// {
	
// }

int	ft_snprintf(char *s, size_t len, const char *fmt, ...)
{
	va_list ap;
	int real_len;

	va_start(ap, fmt);
	real_len = ft_vsnprintf(s, len, fmt, ap);
	va_end(ap);
	return (real_len);
}

// int	ft_vsprintf(char *s, const char *fmt, va_list ap)
// {

// }

// int	ft_sprintf(char *s, const char *fmt, ...)
// {

// }

// int	ft_vdprintf(int fd, const char *fmt, va_list ap)
// {
	
// }

// int	ft_dprintf(int fd, const char *fmt, ...)
// {

// }

// int	ft_dprintf(int fd, const char *fmt, ...)
// {
// 	va_list ap;
// 	int len;

// 	va_start(ap, fmt);
// 	len = ft_vdprintf(fd, fmt, ap);
// 	va_end(ap);
// 	return len;
// }

// int	ft_printf(const char *fmt, ...)
// {
// 	va_list ap;
// 	int len;

// 	va_start(ap, fmt);
// 	len = ft_vdprintf(1, fmt, ap);
// 	va_end(ap);
// 	return len;
// }
