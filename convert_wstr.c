/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:11:34 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/10 19:46:10 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"
#include <wchar.h>

wchar_t	*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	wchar_t	*d;

	d = dst;
	while (len--)
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = '\0';
	*dst = '\0';
	return (d);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

int		convert_wstr(char **dst, wchar_t *src, t_directive *d, int is_char)
{
	t_convertion_len	len;
	size_t				cur;
	size_t				srclen;

	cur = 0;
	if (src == NULL)
		src = L"(null)";
	srclen = is_char ? 1 : ft_wstrlen(src);
	srclen = d->precision && srclen > (unsigned)d->precision
		? d->precision : srclen;
	get_len(&len, d, srclen, 0);
	if ((*dst = (char*)malloc(sizeof(char) * len.total)) == NULL)
		return (-1);
	cur += set_pre(*dst, &len, d, 0);
	ft_wstrncpy((wchar_t*)(*dst + cur), src, srclen);
	cur += srclen;
	cur += set_post(*dst + cur, &len, d);
	return (cur);
}

int		convert_wchar(char **dst, wchar_t src, t_directive *d)
{
	return (convert_wstr(dst, &src, d, 1));
}
