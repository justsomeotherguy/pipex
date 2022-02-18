/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:52:09 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/14 15:10:59 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a string character array and converts the string into an integer
variable. The return value is the integer that is created from the conversion.
*/
int	ft_atoi(const char *str)
{
	int		index;
	int		neg;
	int		res;

	index = 0;
	res = 0;
	neg = 1;
	while (str[index] == '\n' || str[index] == '\t' || str[index] == '\r'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}	
	while (str[index] != '\0' && ft_isdigit(str[index]))
	{
		res = (res * 10) + str[index] - '0';
		index++;
	}
	if (neg == -1)
		return (-res);
	return (res);
}
