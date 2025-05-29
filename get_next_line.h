/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:16:51 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/29 15:30:40 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5000000
#endif

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_caract
{
	char			data;
	struct s_caract	*next;
	bool			is_nl;
} t_caract;

char		*get_next_line(int fd);
void		*ft_calloc(size_t nmemb, size_t size);
void		print_list(t_caract *head);
int			len_before_nl(t_caract *first);
t_caract	*new_t_caract(t_caract *t_caract);
int			spe_len(t_caract *first);

#endif