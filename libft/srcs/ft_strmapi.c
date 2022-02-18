/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:54:36 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:12:57 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a string input and a function input. A new string is created from
the usage of the input function applied onto the input string. The newly
created string is returned.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		index;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	index = 0;
	while (str[index] != '\0')
	{
		str[index] = (*f)(index, str[index]);
		index++;
	}
	return (str);
}
