/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:37:50 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/28 21:08:00 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_num(long n, char *base, char datatype)
{
	int	i;
	int	b_size;

	b_size = ft_strlen(base);
	if (datatype == 'u')
		n = (unsigned int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_num(-n, base, datatype) + 1);
	}
	else if (n < b_size)
		return (ft_print_char(base[n]));
	else
	{
		i = ft_print_num(n / b_size, base, datatype);
		return (i + ft_print_num(n % b_size, base, datatype));
	}
}
