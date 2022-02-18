/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:39:47 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:06:44 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Compares the two array inputs received for up to a designated length.
If there is a difference found in the bytes, the function will
return the value of the difference between bytes.
*/
int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char		*temp1;
	const unsigned char		*temp2;
	size_t					index;

	temp1 = (const unsigned char *)str1;
	temp2 = (const unsigned char *)str2;
	index = 0;
	while (index < len)
	{
		if (temp1[index] != temp2[index])
			return (temp1[index] - temp2[index]);
		index++;
	}
	return (0);
}
