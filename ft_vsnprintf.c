/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:18:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 21:21:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"
#include "libft.h"
#include "convert.h"
#include "linked_buffer.h"
#include <stdarg.h>

static char	*strdup_range(const char *start, const char *end)
{
	char	*s;
	size_t	len;

	len = end - start;
	if ((s = (char*)malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	return (ft_strncpy(s, start, len));
}

#include <printf.h>
int			ft_vsnprintf(char *dst, size_t len, const char *fmt, va_list args)
{
	t_directive	d;
	const char	*start;
	char		*str;
	char		*tmp;
	int			conv_len;
	t_lbuf_head	*lbuf;
	size_t		ret;

	start = fmt;
	lbuf = NULL;
	while (*fmt && (lbuf == NULL || lbuf->total_len < len))
	{
		if (*fmt == '%')
		{
			if (start != fmt)
				lbuf_add(&lbuf, strdup_range(start, fmt), fmt - start);
			++fmt;
			int p = parse(&d, fmt);
			fmt += p;
			conv_len = convert(&d, &tmp, args);
			lbuf_add(&lbuf, tmp, conv_len);
			start = fmt;
		}
		else
			fmt++;
	}
	if (start != fmt && (lbuf == NULL || lbuf->total_len < len))
		lbuf_add(&lbuf, strdup_range(start, fmt), fmt - start);
	if (lbuf == NULL)
		return (0);
	str = lbuf_join(lbuf, len);
	ft_strcpy(dst, str);
	free(str);
	ret = lbuf->total_len > len ? len : lbuf->total_len;
	free(lbuf);
	return ((int)ret);
}
