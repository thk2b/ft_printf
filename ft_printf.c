/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:39:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/02 20:53:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int len;

	va_start(ap, fmt);
	len = ft_vdprintf(1, fmt, ap);
	va_end(ap);
	return len;
}
