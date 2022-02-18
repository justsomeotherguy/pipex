/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:41:43 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/14 12:41:47 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Finds the first occurence of c in the string. If found, returns a pointer to
the first occurence of c within the string or returns NULL if no match was 
found.
*/
char	*ft_strchr(const char *str, int c)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return ((char *)str + index);
		index++;
	}
	if (str[index] == c)
		return ((char *)str + index);
	return (NULL);
}
