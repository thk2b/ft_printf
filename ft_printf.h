/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:38:04 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/03 11:29:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int		ft_vsnprintf(char *s, size_t len, const char *fmt, ...);
int		ft_vasprintf(char **s, const char *fmt, va_list ap);
int		ft_asprintf(char **s, const char *fmt, ...);
int		ft_vsprintf(char *s, const char *fmt, va_list ap);
int		ft_snprintf(char *s, size_t len, const char *fmt, ...);
int		ft_sprintf(char *s, const char *fmt, ...);
int		ft_dvprintf(int fd, const char *fmt, va_list ap);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_printf(const char *fmt, ...);
