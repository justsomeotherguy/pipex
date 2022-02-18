/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:27:43 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:06:40 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Compares the two received null terminated string inputs for up to a designated
length of characters. If there is a difference found in the characters, the
difference between the two character values is returned. 
*/
int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	index;

	index = 0;
	if (len == 0)
		return (0);
	while (index < (len - 1) && str1[index] != '\0' && str2[index] != '\0'
		&& str1[index] == str2[index])
		index++;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
