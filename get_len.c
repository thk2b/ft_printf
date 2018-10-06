/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:01:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 19:49:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"

void	init_len(t_convertion_len *len)
{
	len->left_spaces = 0;
	len->right_spaces = 0;
	len->prefix = 0;
	len->zeros = 0;
	len->value = 0;
	len->total = 0;
}

void	get_len(t_convertion_len *len, t_directive *d, size_t val_len)
{
	size_t total;

	total = val_len;
	init_len(len);
	if (d->flags & F_HASH)
		len->prefix = ft_strchr("Xx", d->convertion) ? 2 : 1;
	total += len->prefix;
	if ((unsigned)d->precision > total)
		len->zeros = d->precision - total;
	total += len->zeros;
	if ((unsigned)d->width > total)
	{
		if (d->flags & F_MINUS)
			len->right_spaces = d->width - total;
		else 
			len->left_spaces = d->width - total;
	}
	total += len->right_spaces + len->left_spaces;
	len->value = val_len;
	len->total = total;
}

// #define TEST
# ifdef TEST
# include <printf.h>
# include "parse.h"

void print_len(t_convertion_len *l)
{
	printf("left:%zu right:%zu zeroes:%zu prefix:%zu value:%zu total:%zu\n",
		l->left_spaces,
		l->right_spaces,
		l->zeros,
		l->prefix,
		l->value,
		l->total);
}

void test0(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "#11.10o";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}
void test1(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "#15.10o";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test2(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "#-15.10o";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test3(void)
{
	t_directive d;
	t_convertion_len l;
	parse(&d, "#x");
	get_len(&l, &d, 5);
	print_len(&l);
}

void test4(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "10x";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test5(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = ".10x";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test6(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "-2.2x";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test7(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "-6.2x";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

void test8(void)
{
	t_directive d;
	t_convertion_len l;
	char s[] = "#-6.2x";
	printf("%s\n", s);
	parse(&d, s);
	get_len(&l, &d, 5);
	print_len(&l);
}

int main(void)
{
	test0();
	test1();
	test2();
	test4();
	test5();
	test6();
	test7();
	test8();
}

#endif
