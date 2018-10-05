/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:13:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 10:57:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directive.h"
#include "convert.h"
#include "libft.h"
#include <stdarg.h>

static unsigned long long	cast_u_arg(va_list ap, t_directive *d)
{
	if (d->precision == 'l')
		return (va_arg(ap, unsigned long));
	if (d->precision == 'L')
		return (va_arg(ap, unsigned long long));
	if (d->precision == 'h')
		return (va_arg(ap, unsigned short));
	if (d->precision == 'H')
		return (va_arg(ap, unsigned char));
	if (d->precision == 'j')
		return (va_arg(ap, uintmax_t));
	if (d->precision == 'j')
		return (va_arg(ap, size_t));
	return (0);
}

static long long			cast_s_arg(va_list ap, t_directive *d)
{
//	if (d->convertion >= 'A' && d->convertion <= 'Z')
	if (d->precision == 'l')
		return (va_arg(ap, long));
	if (d->precision == 'L')
		return (va_arg(ap, long long));
	if (d->precision == 'h')
		return (va_arg(ap, short));
	if (d->precision == 'H')
		return (va_arg(ap, char));
	if (d->precision == 'j')
		return (va_arg(ap, intmax_t));
	if (d->precision == 'j')
		return (va_arg(ap, size_t)); // int?
	return (0);
}

static size_t repeat(size_t n, char c, char *dst)
{
	// while (
}

static size_t set_prefix(t_directive *d, char **dst)
{

}

size_t	set_pre(char *dst, t_convertion_len *len, t_directive *d)
{
	size_t cur;

	cur = 0;
	if (len->left_spaces)
		cur += repeat(len->left_spaces, ' ',dst);
	if (len->prefix)
		cur += set_prefix(d, dst);
	if (len->zeros)
		cur += repeat(len->zeros, '0', dst + cur);
	return (cur);
}

size_t	set_post(char *dst, t_convertion_len *len, t_directive *d)
{
	size_t cur;

	cur = 0;
	if (len->right_spaces)
		cur += repeat(len->right_spaces, ' ', dst);
	return (len);
}

// static char	*convert_ull_base(int base, char **dst, unsigned long long ull, t_directive *d)
// {
// 	t_directive_len len;
// 	size_t			ndigits;
// 	char			*str;

// 	char			*cur;
// 	// static const char	*sym_table[] = {
// 	// 	"0123456789abcdef",
// 	// 	"0123456789ABCDEF"
// 	// };
// 	// char				*sym;


// 	get_len(&len, d, ndigits);
// 	if ((str = (char*)malloc(len.total * sizeof(char))) == NULL)
// 		return (NULL);
// 	set_pre(d, len, str);
	
// 	set_post(d, len, str);
// 	cur = str;
// 	if (len.spaces && (d->flags & F_MINUS) == 0)
// 		cur += repeat(len.spaces, ' ', cur);
// 	if (len.prefix)
// 		cur += set_prefix(d, cur);
// 	if (len.zeros)
// 		cur += repeat(len.zeros, '0', cur);
// 	if (len.digits)
// 		cur += set_digits(d, len.digits, ull, cur);
// 	if (len.spaces && (d->flags & F_MINUS))
// 		cur += repeat(len.spaces, ' ', cur);
// 	return (str);
// }

int	convert(t_directive *d, char **dst, va_list ap)
{
	if (ft_strchr("dDi", d->convertion))
		return (convert_ll_base(10, dst, cast_s_arg(ap, d), d));
	if (d->convertion == 'x')
		return (convert_ull_base(16, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 'o')
		return (convert_ull_base(16, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 'u')
		return (convert_ull_base(10, dst, cast_u_arg(ap, d), d));
	// if (d->convertion == 's')
	// 	return convert_str(dst, va_arg(ap, char *));
	// if (d->convertion == 'S')
	// 	return convert_wstr(dst, va_arg(ap, char *));
	// if (d->convertion == 'c')
	// 	return convert_char(dst, va_arg(ap, int));
}
