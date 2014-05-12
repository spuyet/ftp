/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:31:47 by spuyet            #+#    #+#             */
/*   Updated: 2013/12/01 18:42:50 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	if (lst)
	{
		new = (*f)(lst);
		first = new;
		while (lst)
		{
			new->next = (*f)(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
