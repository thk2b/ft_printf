/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:13:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 18:17:15 by tkobb            ###   ########.fr       */
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
		return (va_arg(ap, int));
	if (d->precision == 'H')
		return (va_arg(ap, int));
	if (d->precision == 'j')
		return (va_arg(ap, uintmax_t));
	if (d->precision == 'j')
		return (va_arg(ap, size_t));
	return (0);
}

// static long long			cast_s_arg(va_list ap, t_directive *d)
// {
// //	if (d->convertion >= 'A' && d->convertion <= 'Z')
// 	if (d->precision == 'l')
// 		return (va_arg(ap, long));
// 	if (d->precision == 'L')
// 		return (va_arg(ap, long long));
// 	if (d->precision == 'h')
// 		return (va_arg(ap, int));
// 	if (d->precision == 'H')
// 		return (va_arg(ap, int));
// 	if (d->precision == 'j')
// 		return (va_arg(ap, intmax_t));
// 	if (d->precision == 'j')
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
		return (convert_ull_base(16, dst, cast_u_arg(ap, d), d));
	if (d->convertion == 'u')
		return (convert_ull_base(10, dst, cast_u_arg(ap, d), d));
	// if (d->convertion == 's')
	// 	return convert_str(dst, va_arg(ap, char *));
	// if (d->convertion == 'S')
	// 	return convert_wstr(dst, va_arg(ap, char *));
	// if (d->convertion == 'c')
	// 	return convert_char(dst, va_arg(ap, int));
	return (0);
}
