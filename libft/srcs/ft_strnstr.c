/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:43:23 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 14:51:58 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Locates a substring within a substring for up to the defined length of
characters. Returns a pointer to the first occurence of the substring in the 
main string. If substring is invalid or 0 characters long, the main string
is returned. If substring is not found in the main string for up to the length,
a pointer to NULL is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index1;
	size_t	index2;

	if (little[0] == '\0')
		return ((char *)big);
	index1 = 0;
	while (big[index1] != '\0' && index1 < len)
	{
		index2 = 0;
		while (big[index1 + index2] != '\0' && little[index2] != '\0'
			&& (index1 + index2) < len
			&& big[index1 + index2] == little[index2])
		{
			index2++;
			if (little[index2] == '\0')
				return ((char *)(big + index1));
		}	
		index1++;
	}
	return (NULL);
}
