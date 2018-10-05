/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:56:18 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 23:17:10 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H
#include "directive.h"
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_directive_len
{
	size_t	spaces;
	size_t	prefix;
	size_t	zeros;
	size_t	sign;
	size_t	digits;
	size_t	total;
}				t_directive_len;

void	get_len(t_directive_len *len, t_directive *d, unsigned long long ull);
int		convert(t_directive *directive, char **dst, va_list ap);

#endif
