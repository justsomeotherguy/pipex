/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:48:51 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:00:02 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Helper function for ft_printf_ptr, parses the received hexidecimal character
string into the received unsigned long to pass the value to ft_putchar_fd
for output.
*/
static void	ft_writehex(char *hex, unsigned long num, t_argcont *allargs)
{
	if (num >= 16)
		ft_writehex(hex, (num / 16), allargs);
	ft_putchar_fd(hex[num % 16], 1);
	allargs->counter++;
}

/*
Output function for ft_printf, takes the received argument and prints a pointer
address in hexidecimal characters.
*/
void	ft_printf_ptr(t_argcont *allargs)
{
	unsigned long		num;
	char				*hex;

	hex = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	allargs->counter = allargs->counter + 2;
	num = va_arg(allargs->args, unsigned long);
	ft_writehex(hex, num, allargs);
}
