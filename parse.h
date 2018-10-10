/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:53:00 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/10 16:08:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "directive.h"
# define IS_FLAG(c) ((c) == '#' || (c) == ' ' || (c) == '-' || (c) == '+')

int	parse_flags(t_directive *d, const char *fmt);
int	parse_length(t_directive *d, const char *fmt);
int	parse(t_directive *directive, const char *fmt);

#endif
