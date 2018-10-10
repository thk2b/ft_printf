/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:40:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/10 15:47:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "directive.h"
#include "parse.h"

static void	reset_directive(t_directive *d)
{
	d->convertion = 0;
	d->flags = 0;
	d->length = 0;
	d->precision = -1;
	d->width = 0;
}

static int	parse_flags(t_directive *d, const char *fmt)
{
	int	len;

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
		{
			if (d->flags & F_MINUS)
				break ;
			d->flags |= F_ZERO;
		}
		else
			break ;
		len++;
	}
	return (len);
}

static int	parse_width(t_directive *d, const char *fmt)
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

static int	parse_precision(t_directive *d, const char *fmt)
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
	else
		d->precision = 0;
	return (len);
}

static int	parse_length(t_directive *d, const char *fmt)
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

static int	parse_convertion(t_directive *d, const char *fmt)
{
	if (*fmt == 'p')
	{
		d->flags |= (F_HASH | F_PTR);
		d->length = 'L';
		d->convertion = 'x';
		return (1);
	}
	if (ft_strchr("DOU", *fmt))
		d->length = 'l';
	d->convertion = *fmt;
	return (1);
}

int			parse(t_directive *d, const char *fmt)
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
