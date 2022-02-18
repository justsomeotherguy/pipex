/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:49:55 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 14:14:08 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Copies the content of a received source string and overrides the destination
string up to the defined length. Returns the destination string with the
copied contents from source string. Returns a pointer to NULL if the source
and destination strings are not valid.
*/
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char			*str1;
	char			*str2;
	size_t			index;

	if (!dest && !src)
		return (NULL);
	str1 = (char *)dest;
	str2 = (char *)src;
	index = 0;
	while (index < len)
	{
		str1[index] = str2[index];
		index++;
	}
	return (dest);
}
