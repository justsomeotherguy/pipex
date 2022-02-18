/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:16:06 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:20:19 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a linked list and an input function. Applies the function to every
item in the linked list, simultaneously creating a new linked list with the
output of the input funciton. Returns the new list created with the content 
modified by the input function.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*res;
	t_list		*temp;

	if (!lst || !f)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	res = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&res, del);
		}
		lst = lst->next;
		ft_lstadd_back(&res, temp);
	}
	return (res);
}
