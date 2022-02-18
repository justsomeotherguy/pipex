/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:02:59 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/14 12:40:05 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Takes one string and appends another string to create a newly combined string.
First allocates memory to create a new string of the combined length of s1 and 
s2. Use s1 as source string, s2 as the string to append to the source string. 
Returns the combined string.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			index;
	int			index2;

	index = 0;
	index2 = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[index] != '\0')
		str[index2++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		str[index2++] = s2[index++];
	str[index2] = '\0';
	return (str);
}
