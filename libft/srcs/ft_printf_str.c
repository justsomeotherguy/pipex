/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:36:47 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 16:02:06 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Output function for ft_printf, takes the received argument and passes it to
ft_putstr_fd to print a string of characters.
*/
void	ft_printf_str(t_argcont *args)
{
	char	*str;

	str = va_arg(args->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		args->counter = args->counter + 6;
	}
	else
	{
		args->counter = (args->counter + ft_strlen(str));
		ft_putstr_fd(str, 1);
	}
}
