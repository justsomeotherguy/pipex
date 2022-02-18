/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:42:01 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 14:32:26 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Searches the received string input for the last occurence of an input
character. If a match is found, returns a pointer to the last occurence of the
character in the string, otherwise returns NULL.
*/
char	*ft_strrchr(const char *str, int c)
{
	int		index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == c)
			return ((char *)(str + index));
		index--;
	}
	return (NULL);
}
