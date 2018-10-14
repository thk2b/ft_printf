/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:07:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/13 22:33:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H
# include "directive.h"
# define S_EOC 1
# define S_RED 2
# define S_GREEN 4
# define S_BLUE 8
# define S_BLACK 16
# define S_WHITE 32
# define S_YELLOW 64
# define S_CYAN 128

int	parse_style(t_directive *directive, const char *fmt);
int	convert_style(char **dst, t_directive *directive);

#endif
