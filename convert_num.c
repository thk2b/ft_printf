/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:04:52 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/06 23:02:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"
#include <printf.h>

static unsigned long long get_pow(int base, unsigned long long ull, size_t *ndigits)
{
	unsigned long long	pow;
	unsigned long long	npow;
	size_t				len;

	pow = 1;
	len = 1;
	while ((npow = pow * base) <= ull && npow)
	{
		pow = npow;
		len++;
	}
	*ndigits = len;
	return (pow);
}

static int set_digits(int base, char *dst, unsigned long long ull, unsigned long long pow, int upcase)
{
	static char	*syms[] = {"0123456789abcdef", "0123456789ABCDEF"};
	char		*sym;
	char		*start;

	start = dst;
	sym = upcase ? syms[1] : syms[0];
	while (pow)
	{
		*dst++ = sym[ull / pow % base];
		pow /= base;
	}
	return (dst - start);
}

#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
int convert_ull_base(int base, char **dst, unsigned long long ull, t_directive *d)
{
	t_convertion_len	len;
	unsigned long long	pow;
	size_t				ndigits;
	char				*t;

	ndigits = 0;
	pow = get_pow(base, ull, &ndigits);
	get_len(&len, d, ndigits, 0);
	if ((*dst = (char*)malloc(sizeof(char) * len.total)) == NULL)
		return (-1);
	t = *dst;
	t += set_pre(t, &len, d, 0);
	t += set_digits(base, t, ull, pow, ISUPPER(d->convertion));
	set_post(t, &len, d);
	return (len.total);
}

int convert_ll_base(int base, char **dst, long long ll, t_directive *d)
{
	t_convertion_len	len;
	unsigned long long	pow;
	unsigned long long	ull;
	size_t				ndigits;
	char				*t;

	ull = ll < 0 ? (unsigned long long)(-1 * ll) : (unsigned long long)ll;
	ndigits = 0;
	pow = get_pow(base, ull, &ndigits);
	get_len(&len, d, ndigits, ll < 0);
	if ((*dst = (char*)malloc(sizeof(char) * len.total)) == NULL)
		return (-1);
	t = *dst;
	t += set_pre(t, &len, d, ll < 0);
	t += set_digits(base, t, ull, pow, ISUPPER(d->convertion));
	set_post(t, &len, d);
	return (len.total);
}
