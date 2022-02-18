/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:59:07 by jwilliam          #+#    #+#             */
/*   Updated: 2021/12/20 14:14:05 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
Receives a character and file descriptor and uses the write function to output
the input character.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
