/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:13:33 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/03 18:00:26 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int p, size_t size)
{
	size_t			i;
	unsigned char	*memo;

	i = 0;
	memo = (unsigned char *)dest;
	while (i < size)
		memo[i++] = p;
	return (memo);
}
