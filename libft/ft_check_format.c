/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:36:19 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/19 19:10:23 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(char datatype, va_list ap)
{
	int	i;

	i = 0;
	if (datatype == 'c')
		i += ft_print_char(va_arg(ap, int));
	else if (datatype == 's')
		i += ft_print_str(va_arg(ap, char *));
	else if (datatype == 'd' || datatype == 'i' || datatype == 'u')
		i += ft_print_num((long)(va_arg(ap, int)), DEC, datatype);
	else if (datatype == 'x')
		i += ft_print_num((long)(va_arg(ap, unsigned int)), HEXL, datatype);
	else if (datatype == 'X')
		i += ft_print_num((long)(va_arg(ap, unsigned int)), HEXU, datatype);
	else if (datatype == 'p')
		i += ft_print_ptr(va_arg(ap, size_t), HEXL);
	else
		i += write(1, &datatype, 1);
	return (i);
}
