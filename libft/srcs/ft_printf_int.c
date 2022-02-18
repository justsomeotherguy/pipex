/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:48:50 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 15:58:16 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Helper function for ft_printf_int. Receives an integer and returns the amount
of digits the integer is.
*/
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

/*
Output function for ft_printf, takes the received argument and passes it to
ft_putnbr_fd to print the output of received integer.
*/
void	ft_printf_int(t_argcont *allargs)
{
	int		len;
	int		num;

	num = va_arg(allargs->args, int);
	len = ft_get_size(num);
	ft_putnbr_fd(num, 1);
	allargs->counter = allargs->counter + len;
}
