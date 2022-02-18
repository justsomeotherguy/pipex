/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:41:40 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/16 13:48:19 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a string and replaces the contents of the string up to the defined
length with a defined character. Returns the modified string with the replaced
characters.
*/
void	*ft_memset(void *str, int c, size_t len)
{
	char			*ptr;
	size_t			index;

	ptr = str;
	index = 0;
	while (index < len)
	{
		ptr[index] = c;
		index++;
	}
	return (str);
}
