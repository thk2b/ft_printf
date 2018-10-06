/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:13:50 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/06 16:22:43 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"

int	convert_str(char **dst, char *src, t_directive *d, int is_char)
{
	t_convertion_len	len;
	size_t				cur;
	size_t				srclen;

	cur = 0;
	srclen = is_char ? 1 : ft_strlen(src);
	get_len(&len, d, srclen, 0);
	if ((*dst = (char*)malloc(sizeof(char) * len.total)) == NULL)
		return (-1);
	cur += set_pre(*dst, &len, d, 0);
	ft_strcpy(*dst + cur, src);
	cur += srclen;
	cur += set_post(*dst + cur, &len, d);
	return (cur);
}

int	convert_char(char **dst, char src, t_directive *d)
{
	return (convert_str(dst, &src, d, 1));
}
