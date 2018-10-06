/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:40:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 21:34:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "directive.h"
#include "parse.h"

static void reset_directive(t_directive *d)
{
	d->convertion = 0;
	d->flags = 0;
	d->length = 0;
	d->precision = 0;
	d->width = 0;
}

#define IS_FLAG(c) ((c) == '#' || (c) == ' ' || (c) == '-' || (c) == '+')
static int parse_flags(t_directive *d, const char *fmt)
{
	int len;

	len = 0;
	while (1)
	{
		if (fmt[len] == '#')
			d->flags |= F_HASH;
		else if (fmt[len] == '-')
			d->flags |= F_MINUS;
		else if (fmt[len] == '+')
			d->flags |= F_PLUS;
		else if (fmt[len] == ' ')
			d->flags |= F_SPACE;
		else if (fmt[len] == '0')
			d->flags |= F_ZERO;
		else
			break;
		len++;
	}
	return (len);
}

static int parse_width(t_directive *d, const char *fmt)
{
	int len;

	len = 0;
	if (ft_isdigit(*fmt))
	{
		d->width = ft_atoi(fmt);
		while (ft_isdigit(fmt[len]))
			len++;
		return (len);
	}
	return (0);
}

static int parse_precision(t_directive *d, const char *fmt)
{
	int len;

	if (*fmt != '.')
		return (0);
	len = 1;
	if (ft_isdigit(fmt[len]))
	{
		d->precision = ft_atoi(fmt + len);
		while (ft_isdigit(fmt[len]))
			len++;
		return (len);
	}
	return (len);
}

static int parse_length(t_directive *d, const char *fmt)
{
	if (ft_strncmp(fmt, "hh", 2) == 0)
		d->length = 'H';
	else if (*fmt == 'h')
		d->length = 'h';
	else if (ft_strncmp(fmt, "ll", 2) == 0)
		d->length = 'L';
	else if (*fmt == 'l')
		d->length = 'l';
	else if (*fmt == 'j')
		d->length = 'j';
	else if (*fmt == 'z')
		d->length = 'z';
	if (d->length >= 'A' && d->length <= 'Z')
		return (2);
	if (d->length >= 'a' && d->length <= 'z')
		return (1);
	return (0);
}

static int parse_convertion(t_directive *d, const char *fmt)
{
	d->convertion = *fmt;
	return (1);
}

int parse(t_directive *d, const char *fmt)
{
	int len;

	reset_directive(d);
	len = 0;
	len += parse_flags(d, fmt + len);
	len += parse_width(d, fmt + len);
	len += parse_precision(d, fmt + len);
	len += parse_length(d, fmt + len);
	len += parse_convertion(d, fmt + len);
	return (len);
}

// #define TEST
#ifdef TEST
# include <printf.h>

void print_directive(t_directive *d)
{
	printf("flags (#:%d, -:%d, +:%d, ' ':%d)\n",
		(d->flags & F_HASH) >= 1,
		(d->flags & F_MINUS) >= 1,
		(d->flags & F_PLUS) >= 1,
		(d->flags & F_SPACE) >= 1
	);
	printf("width (%d)\n", d->width);
	printf("precision (%d)\n", d->precision);
	printf("length (%c)\n", d->length);
	printf("convertion (%c)\n", d->convertion);
}

void test1(void)
{
	t_directive d;
	char s[] = "-.10llx";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test2(void)
{
	t_directive d;
	char s[] = "#10lld";
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test3(void)
{
	t_directive d;
	char s[] = "#10.15lld";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test4(void)
{
	t_directive d;
	char s[] = "#-+10.15lld";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test55(void)
{
	t_directive d;
	char s[] = "#-+d";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test5(void)
{
	t_directive d;
	char s[] = "lld";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test6(void)
{
	t_directive d;
	char s[] = "d";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test7(void)
{
	t_directive d;
	char s[] = ".10d";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test8(void)
{
	t_directive d;
	char s[] = "#10d";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
void test9(void)
{
	t_directive d;
	char s[] = "#.10d";
	
	int len = parse(&d, s);
	printf("-> %s\n", s);
	print_directive(&d);
	printf("len (%d)\n", len);
}
int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test55();
	test6();
	test7();
	test8();
	test9();
}

#endif
