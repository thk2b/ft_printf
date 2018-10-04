/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:43:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 10:25:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F_MINUS 1
#define F_PLUS 2
#define F_HASH 4
#define F_ZERO 8
#define F_SPACE 16

#define L_H 1
#define L_HH 2
#define L_L 4
#define L_LL 8
#define L_J 16
#define L_Z 32

typedef struct	s_directive
{
	int		flags;
	int		width;
	int		precision;
	int		length;
	char	convertion;
}				t_directive;
