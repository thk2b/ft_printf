/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:46:36 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/04 17:53:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_BUFFER_H
# define LINKED_BUFFER_H
# include <stdlib.h>

typedef struct	s_lbuf_block
{
	size_t				len;
	char				*data;
	struct s_lbuf_block	*next;
}				t_lbuf_block;

typedef struct	s_lbuf_head
{
	size_t			total_len;
	size_t			max_len;
	t_lbuf_block	*data;
	t_lbuf_block	*last_block;
}				t_lbuf_head;

#endif
