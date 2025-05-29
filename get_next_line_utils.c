/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:25:59 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/29 15:05:49 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	r;
	void	*res;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	r = nmemb * size;
	res = malloc(r);
	if (res == NULL || r / size != nmemb)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

int	spe_len(t_caract *first)
{
	int			i;
	t_caract	*courant;

	i = 0;
	courant = first;
	while (courant != NULL)
	{
		courant = courant->next;
		i++;
	}
	return (i);
}

int	len_before_nl(t_caract *first)
{
	int	i;
	t_caract	*courant;

	i = 0;
	courant = first;
	while (courant != NULL)
	{
		if (courant->is_nl == true)
			return (i - 1);
		i++;
	}
	return (-1);
}

t_caract	*new_t_caract(t_caract *t_caract)
{
	if (t_caract->data == '\n')
		t_caract->is_nl = true;
	else
		t_caract->is_nl = false;
	t_caract->next = NULL;
	return (t_caract);
}