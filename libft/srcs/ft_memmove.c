/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:13:33 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 14:14:08 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Copies the content of source, stores the content into a temporary array and
moves the content to the destination, up to the length defined. The function
returns the destination string created. Returns NULL pointer if destination
and/or source are invalid.
*/
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*str1temp;
	char			*str2temp;
	size_t			index;

	if (!dest && !src)
		return (NULL);
	str1temp = (char *)dest;
	str2temp = (char *)src;
	index = 0;
	if (dest < src)
	{
		while (len > 0)
		{
			str1temp[index] = str2temp[index];
			index++;
			len--;
		}
	}
	else
	{
		index = len;
		while (index--)
			str1temp[index] = str2temp[index];
	}
	return (dest);
}
