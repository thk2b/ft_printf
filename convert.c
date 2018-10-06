/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:13:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 21:34:17 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directive.h"
#include "convert.h"
#include "libft.h"
#include <stdarg.h>
#include <printf.h>

static unsigned long long	cast_u_arg(va_list ap, t_directive *d)
{
	printf("%c\n", d->precision);
	if (d->length == 'l')
		return (va_arg(ap, unsigned long));
	if (d->length == 'L')
		return (va_arg(ap, unsigned long long));
	if (d->length == 'h')
		return (va_arg(ap, int));
	if (d->length == 'H')
		return (va_arg(ap, int));
	if (d->length == 'j')
		return (va_arg(ap, uintmax_t));
	if (d->length == 'j')
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

// static long long			cast_s_arg(va_list ap, t_directive *d)
// {
// //	if (d->convertion >= 'A' && d->convertion <= 'Z')
// 	if (d->length == 'l')
// 		return (va_arg(ap, long));
// 	if (d->length == 'L')
// 		return (va_arg(ap, long long));
// 	if (d->length == 'h')
// 		return (va_arg(ap, int));
// 	if (d->length == 'H')
// 		return (va_arg(ap, int));
// 	if (d->length == 'j')
// 		return (va_arg(ap, intmax_t));
// 	if (d->length == 'j')
// 		return (va_arg(ap, size_t)); // int?
// 	return (0);
// }

int	convert(t_directive *d, char **dst, va_list ap)
{
	// if (ft_strchr("dDi", d->convertion))
	// 	return (convert_ll_base(10, dst, cast_s_arg(ap, d), d));
	if (d->convertion == 'x')
		return (convert_ull_base(16, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 'o')
		return (convert_ull_base(8, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 'u')
		return (convert_ull_base(10, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 's')
		return convert_str(dst, va_arg(ap, char *), d);
	// if (d->convertion == 'S')
	// 	return convert_wstr(dst, va_arg(ap, char *));
	// if (d->convertion == 'c')
	// 	return convert_char(dst, va_arg(ap, int));
	return (0);
}
