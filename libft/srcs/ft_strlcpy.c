/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:28:26 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:34:41 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Takes two input strings and copies the source string to the destination for
up to the length defined, otherwise copy up to the amount of characters until
the null terminated character. Returns the value of the amount of characters
copied.
*/
int	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t		index;

	index = 0;
	if (len > 0)
	{
		while (src[index] != '\0' && (index < (len - 1)))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index] != '\0')
		index++;
	return (index);
}
