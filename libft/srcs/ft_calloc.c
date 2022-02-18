/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:56:00 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/16 13:00:06 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
The function will allocate memory and return a pointer to the memory allocated.
In addition to allocating memory, the function will set allocated memory to
zero.
*/
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}
