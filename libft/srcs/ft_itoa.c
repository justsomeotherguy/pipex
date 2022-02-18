/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:31:55 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/16 13:11:13 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_get_size(int n)
{
	int		size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_strrev(char *str)
{
	char		temp;
	size_t		index;
	size_t		len;

	index = 0;
	len = ft_strlen(str);
	while (index < (len / 2))
	{
		temp = str[index];
		str[index] = str[(len - index) - 1];
		str[(len - index) - 1] = temp;
		index++;
	}
}

/*
Converts the received integer to a character string. Returns the character
string created from the conversion.
*/
char	*ft_itoa(int n)
{
	char			*res;
	int				index;
	unsigned int	num;
	int				size;

	size = ft_get_size(n);
	res = ft_calloc((size) + 1, sizeof(char));
	if (!res)
		return (NULL);
	num = n;
	if (n < 0)
		num = -n;
	index = 0;
	while (num >= 10)
	{
		res[index++] = (num % 10) + '0';
		num = (num / 10);
	}
	res[index++] = num + '0';
	if (n < 0)
		res[index] = '-';
	ft_strrev(res);
	return (res);
}
