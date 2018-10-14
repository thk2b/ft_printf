/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:02:56 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/13 22:35:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include "libft.h"
#include <printf.h>

static void	set_colors1(t_directive *d, const char *name, int len)
{
	if (ft_strnequ(name, "eoc", len))
		d->flags |= S_EOC;
	else if (ft_strnequ(name, "red", len))
		d->flags |= S_RED;
	else if (ft_strnequ(name, "green", len))
		d->flags |= S_GREEN;
	else if (ft_strnequ(name, "blue", len))
		d->flags |= S_BLUE;
	else if (ft_strnequ(name, "white", len))
		d->flags |= S_WHITE;
	else if (ft_strnequ(name, "black", len))
		d->flags |= S_BLACK;
	else if (ft_strnequ(name, "yellow", len))
		d->flags |= S_YELLOW;
	else if (ft_strnequ(name, "cyan", len))
		d->flags |= S_CYAN;
}

int			parse_style(t_directive *d, const char *fmt)
{
	int		len;
	char	*end;

	len = 1;
	d->convertion = '{';
	end = ft_strchr(fmt, '}');
	if (end == NULL)
		return (len);
	len += end - fmt;
	set_colors1(d, fmt + 1, len - 2);
	return (len);
}

static int	apply_style(char **dst, const char *code)
{
	size_t	len;

	len = ft_strlen(code);
	if ((*dst = (char*)malloc(sizeof(char) * len)) == NULL)
		return (-1);
	ft_strncpy(*dst, code, len);
	return (len);
}

int			convert_style(char **dst, t_directive *d)
{
	if (d->flags & S_EOC)
		return (apply_style(dst, "\x1b[0m"));
	else if (d->flags & S_RED)
		return (apply_style(dst, "\x1b[31m"));
	else if (d->flags & S_GREEN)
		return (apply_style(dst, "\x1b[32m"));
	else if (d->flags & S_BLUE)
		return (apply_style(dst, "\x1b[34m"));
	else if (d->flags & S_WHITE)
		return (apply_style(dst, "\x1b[37m"));
	else if (d->flags & S_BLACK)
		return (apply_style(dst, "\x1b[30m"));
	else if (d->flags & S_YELLOW)
		return (apply_style(dst, "\x1b[33m"));
	else if (d->flags & S_CYAN)
		return (apply_style(dst, "\x1b[36m"));
	return (0);
}
