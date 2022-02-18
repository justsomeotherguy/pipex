/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:48:50 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:01:29 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Helper function for ft_printf_int. Receives an unsigned integer and returns
the amount of digits the unsigned integer is.
*/
static void	ft_putunbr(unsigned int n, int fd, t_argcont *allargs)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
		allargs->counter++;
	}
	else
	{
		ft_putunbr(n / 10, fd, allargs);
		c = (n % 10) + '0';
		write(fd, &c, 1);
		allargs->counter++;
	}	
}

/*
Output function for ft_printf, takes the received argument and passes it to
the helper function to print the output of received unsigned integer.
*/
void	ft_printf_uint(t_argcont *allargs)
{
	unsigned int		num;

	num = va_arg(allargs->args, unsigned int);
	ft_putunbr(num, 1, allargs);
}
