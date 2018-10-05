/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:19:51 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 17:09:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdarg.h>
#include <limits.h>

void d(char *fmt, unsigned long long ull)
{
	printf(fmt, ull);
}

unsigned long long convert(va_list ap, int flag)
{
	if (flag == 1)
		return va_arg(ap, long long);
	if (flag == 2)
		return va_arg(ap, int);
	return va_arg(ap, unsigned int);
}

void f(char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	d(fmt, convert(ap, 2));
	va_end(ap);
}

int main(void)
{
	char s[2];
	snprintf(s, 2, "123 %d", 123);
	printf("%s\n", s);
}
