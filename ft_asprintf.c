/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:18:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/06 17:20:30 by tkobb            ###   ########.fr       */
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

int		ft_vasprintf(char **dst, const char *fmt, va_list args)
{
	t_directive	d;
	const char	*start;
	char		*tmp;
	int			conv_len;
	t_lbuf_head	*lbuf;
	size_t		ret;

	start = fmt;
	lbuf = NULL;
	while (*fmt)
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
	if (start != fmt)
		lbuf_add(&lbuf, strdup_range(start, fmt), fmt - start);
	if (lbuf == NULL)
		return (0);
	*dst = lbuf_join(lbuf);
	ret = lbuf->total_len;
	free(lbuf);
	return ((int)ret);
}

int	ft_asprintf(char **s, const char *fmt, ...)
{
	va_list ap;
	int len;

	va_start(ap, fmt);
	len = ft_vasprintf(s, fmt, ap);
	va_end(ap);
	return (len);
}
