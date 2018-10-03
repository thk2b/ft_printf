/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:39:34 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/02 20:53:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_dprintf(int fd, const char **fmt, ...)
{
	va_list ap;
	int len;

	va_start(ap, fmt);
	len = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return len;
}
