/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:56:18 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/05 10:52:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H
#include "directive.h"
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_convertion_len
{
	size_t	left_spaces;
	size_t	right_spaces;
	size_t	prefix;
	size_t	zeros;
	size_t	sign;
	size_t	digits;
	size_t	total;
}				t_convertion_len;

void	get_len(t_convertion_len *len, t_directive *d, unsigned long long ull);
size_t	set_pre(char **dst, t_convertion_len *len, t_directive *d);
size_t	set_post(char **dst, t_convertion_len *len, t_directive *d);
int		convert_ll_base(int base, char **dst, long long ll, t_directive *d);
int		convert_ull_base(int base, char **dst, unsigned long long ull, t_directive *d);
int		convert_str(char **dst, char *src, t_directive *d);
int		convert_char(char **dst, char src, t_directive *d);
int		convert(t_directive *directive, char **dst, va_list ap);

#endif
