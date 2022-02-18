/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:48:22 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:38:09 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a string input and a function input. Applies the input function to
every character in the string.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		index;

	if (!s)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		f(index, (s + index));
		index++;
	}
}
