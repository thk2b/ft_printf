/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:07:34 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/03 11:17:18 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directive.h"

int	print(int fd, t_directive *directive);
int	print_range(int fd, const char *from, const char *to);
int	print_str(int fd, const char *s);
