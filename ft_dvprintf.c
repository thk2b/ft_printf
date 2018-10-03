/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dvprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:50:02 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/03 11:18:11 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser.h"
#include "converter.h"
#include <stdarg.h>

int	ft_dvprintf(int fd, const char *fmt, va_list ap)
{
	t_directive	directive;
	int			len;
	char		*start;

	start = fmt;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (fmt != start)
				len += print_range(fd, start, fmt);
			fmt += parse(&directive, *++fmt);
			start = fmt;
			len += print(fd, &directive, ap);
		}
		else
			fmt++;
	}
	if (fmt != start)
		len += print_str(fd, fmt);
	return (len);
}
