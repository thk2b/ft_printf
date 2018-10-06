/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:48:52 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 22:01:36 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"
#include <printf.h>

static size_t repeat(size_t n, char c, char *dst)
{
	size_t	cur;

	cur = 0;
	while (cur < n)
		dst[cur++] = c;
	return (n);
}

static size_t set_prefix(t_directive *d, char *dst)
{
	if ((d->flags & F_HASH) == 0)
		return (0);
	if (ft_strchr("xX", d->convertion))
	{
		*(dst) = '0';
		*(dst + 1) = 'x';
		return (2);
	}
	*dst = '0';
	return (1);
}

size_t	set_pre(char *dst, t_convertion_len *len, t_directive *d)
{
	size_t cur;

	(void)d;
	cur = 0;
	if (len->left_spaces)
		cur += repeat(len->left_spaces, ' ', dst);
	if (len->prefix)
		cur += set_prefix(d, dst);
	if (len->zeros)
		cur += repeat(len->zeros, '0', dst + cur);
	return (cur);
}

size_t	set_post(char *dst, t_convertion_len *len, t_directive *d)
{
	size_t cur;

	(void)d;
	cur = 0;
	if (len->right_spaces)
		cur += repeat(len->right_spaces, ' ', dst);
	return (cur);
}
