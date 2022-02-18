/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:48:46 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:00:17 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Helper function for ft_printf_hex, parses the received hexidecimal character
string into the received unsigned integer to pass the value to ft_putchar_fd 
for output.
*/
static void	ft_writehex(char *str, unsigned int num, t_argcont *allargs)
{
	if (num >= 16)
		ft_writehex(str, (num / 16), allargs);
	ft_putchar_fd(str[num % 16], 1);
	allargs->counter++;
}

/*
Output function for ft_printf, takes the received argument and prints a
hexidecimal character, input character determines whether to print in
uppercase or lowercase.
*/
void	ft_printf_hex(int c, t_argcont *allargs)
{
	char			*upper;
	char			*lower;
	unsigned int	num;

	num = va_arg(allargs->args, unsigned int);
	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (c == 'x')
		ft_writehex(lower, num, allargs);
	else if (c == 'X')
		ft_writehex(upper, num, allargs);
}
