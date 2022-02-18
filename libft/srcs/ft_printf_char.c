/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:47:54 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:00:20 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Output function for ft_printf, takes the received argument and passes it to
ft_putchar_fd to print a character.
*/
void	ft_printf_char(t_argcont *allargs)
{
	ft_putchar_fd(va_arg(allargs->args, int), 1);
	allargs->counter++;
}
