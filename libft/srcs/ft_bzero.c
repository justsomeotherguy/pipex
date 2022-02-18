/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:35:22 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/16 13:01:22 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a string and erases/writes '\0' null terminating characters in the
string up to the length designated by len. Returns the pointer to the string
cleared.
*/
void	ft_bzero(void *str, size_t len)
{
	char			*ptr;
	size_t			index;

	index = 0;
	ptr = str;
	while (index < len)
	{
		ptr[index] = '\0';
		index++;
	}
}
