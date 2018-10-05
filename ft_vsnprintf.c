/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:18:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 17:57:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser.h"
#include "linked_buffer.h"
#include <stdarg.h>

int	vsnprintf(char *s, size_t len, const char *fmt, va_list args)
{
	t_directive	d;
	char		*start;
	int			len;
	char		*tmp;
	t_lbuf_head	*lbuf;

	start = fmt;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (start != fmt)
				;// len += putstrrange(start, fmt - 1);
			fmt += parse(&d, ++fmt) + 1;
			len = convert(&d, &tmp, args);
			lbuf_add(lbuf, convert(&d, fmt));
			start = fmt;
		}
		fmt++;
	}
	if (start != fmt)
		;//len += putstr(start);

}
