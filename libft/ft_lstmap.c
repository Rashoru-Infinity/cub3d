/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:00:28 by khagiwar          #+#    #+#             */
/*   Updated: 2020/10/16 23:00:36 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list *newlst;
	t_list *curr;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	curr = newlst;
	while (lst)
	{
		if (!(curr->next = ft_lstnew(f(lst->content))))
		{
			while (newlst)
			{
				curr = newlst->next;
				ft_lstdelone(newlst, d);
				newlst = curr;
			}
			return (NULL);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (newlst);
}
