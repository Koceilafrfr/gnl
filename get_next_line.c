/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:44:39 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/29 20:23:20 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_caract	*treat_buf(char *buf, t_caract *first)
{
	t_caract	*current;
	t_caract	*new;

	current = first;
	if (current == NULL)
	{
		current = (t_caract *)ft_calloc(sizeof(t_caract), 1);
		if (!current)
			return (NULL);
		current->data = *buf++;
		first = new_t_caract(current);
	}
	while (current->next != NULL)
		current = current->next;
	while (*buf != '\0')
	{
		new = (t_caract *)ft_calloc(sizeof(t_caract), 1);
		if (!new)
			return (free(new), NULL);
		new->data = *buf;
		current->next = new_t_caract(new);
		current = new;
	}
	return (first);
}

static t_caract	*get_new_first(t_caract *first)
{
	t_caract	*current;
	t_caract	*tmp;

	current = first;
	while (current != NULL && current->is_nl)
	{
		tmp = current;
		current = current->next;
		free (tmp);
	}
	if (current && current->is_nl)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	return (current);
}

static char	*out(t_caract *first)
{
	char		*out_line;
	int			i;
	int			len;
	t_caract	*current;

	i = 0;
	if (!first->data)
		return (NULL);
	len = spe_len(first);
	out_line = (char *)ft_calloc(sizeof(char), len + 1);
	if (!out_line)
		return (NULL);
	current = first;
	while (i < len)
	{
		out_line[i] = current->data;
		current = current->next;
		i++;
	}
	out_line[i] = '\0';
	return (out_line);
}

char	*get_next_line(int fd)
{
	static t_caract	*first;
	char			*buf;
	char			*out_line;
	int				state;

	state = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (len_before_nl(first) == -1 && state > 0)
	{
		buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE);
		if (!buf)
			return (NULL);
		if (state > 0)
			buf[state] = '\0';
		first = treat_buf(buf, first);
			free (buf);
	}
	out_line = out(first);
 	first = get_new_first(first);
	return (out_line);
}
