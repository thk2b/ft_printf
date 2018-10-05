/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:18:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 21:32:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"
#include "linked_buffer.h"
#include <stdarg.h>

int			vsnprintf(char *s, size_t len, const char *fmt, va_list args)
{
	t_directive	d;
	char		*start;
	char		*str;
	char		*tmp;
	int			conv_len;
	t_lbuf_head	*lbuf;
	size_t		ret;

	start = fmt;
	while (*fmt && lbuf->total_len < len)
	{
		if (*fmt == '%')
		{
			if (start != fmt)
				lbuf_add(&lbuf, strdup_range(start, fmt), fmt - start);
			fmt += parse(&d, ++fmt) + 1;
			conv_len = convert(&d, &tmp, args);
			lbuf_add(&lbuf, tmp, conv_len);
			start = fmt;
		}
		fmt++;
	}
	if (start != fmt && lbuf->total_len < len)
		lbuf_add(&lbuf, strdup_range(start, fmt), fmt - start);
	str = lbuf_join(lbuf, len);
	ft_strcpy(s, str);
	free(str);
	ret = lbuf->total_len;
	free(lbuf);
	return ((int)ret);
}
