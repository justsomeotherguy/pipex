/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:13:48 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:15:11 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Parses through a linked list and removes all entries inside the list using
the input delete function.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*temp;
	t_list	*store;

	temp = *lst;
	if (!*lst)
		return ;
	while (temp)
	{
		store = temp->next;
		ft_lstdelone(temp, del);
		temp = store;
	}
	*lst = NULL;
}
