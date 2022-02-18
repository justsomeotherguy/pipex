/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:07:29 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/16 13:14:21 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Searches the string input for a designated character for up to the defined
length. If an instance of the character was found, the function will return
a pointer to the first occurance of the character within the string. Otherwise
the function will return a pointer to NULL if there was no matching character.
*/
void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t		index;

	index = 0;
	while (index < len)
	{
		if (*(unsigned char *)(str + index) == (unsigned char)c)
			return ((void *)(str + index));
		index++;
	}
	return (NULL);
}
