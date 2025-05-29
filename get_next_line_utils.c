/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:25:59 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/29 17:39:24 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

int	spe_len(t_caract *first)
{
	int	i;

	i = 0;
	while (first != NULL)
	{
		i++;
		if (first->is_nl)
			break;
		first = first->next;
	}
	return (i);
}

int	len_before_nl(t_caract *first)
{
	int	i;

	i = 0;
	while (first != NULL)
	{
		if (first->is_nl == true)
			return (i);
		first = first->next;
		i++;
	}
	return (-1);
}

t_caract	*new_t_caract(t_caract *car)
{
	if (car->data == '\n')
		car->is_nl = true;
	else
		car->is_nl = false;
	car->next = NULL;
	return (car);
}

// t_caract	*treat_buf(char *buf, t_caract *first)
// {
// 	t_caract	*current;
// 	t_caract	*new;

// 	if (!first)
// 	{
// 		first = (t_caract *)ft_calloc(1, sizeof(t_caract));
// 		if (!first)
// 			return (NULL);
// 		first->data = *buf++;
// 		first = new_t_caract(first);
// 		current = first;
// 	}
// 	else
// 	{
// 		current = first;
// 		while (current->next != NULL)
// 			current = current->next;
// 	}
// 	while (*buf)
// 	{
// 		new = (t_caract *)ft_calloc(1, sizeof(t_caract));
// 		if (!new)
// 			return (NULL);
// 		new->data = *buf++;
// 		current->next = new_t_caract(new);
// 		current = current->next;
// 	}
// 	return (first);
// }
