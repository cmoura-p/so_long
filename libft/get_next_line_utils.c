/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:50:04 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/17 19:53:23 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s + 1);
		s++;
	}
	return (NULL);
}

size_t	ft_getlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_getjoin(char *s1, char *s2)
{
	char	*s3;

	auto size_t i = 0;
	auto size_t j = 0;
	auto size_t size_s1 = ft_getlen(s1);
	auto size_t size_s2 = ft_getlen(s2);
	if (!s1)
		s1 = (char *) ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *) ft_calloc((size_s1 + size_s2 + 1), sizeof(char));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	while (j < size_s1)
		s3[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		s3[i++] = s2[j++];
	free(s1);
	free(s2);
	return (s3);
}

void	ft_getcpy(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		*((unsigned char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}

// ft_getchr
// verifica se existe o caracter passado em c no pointer de char passado em s
// devolve a string encontrada ate o caracter

// ft_getcpy
// aqui esta sendo passado o segment e por ser uma variavel estatica
// seu conteudo vai ser alterado pela funcao.
// Primeiro procura se existe linha
// se nao existrir preenche todo o segmento com nulo, mas se existir
// O inicio, ate o '\n', vai sendo substituido pelo o que tem depois do '\n'
// depois de feito, o restante eh preeenchido com zero

// ft_getjoin junta em s3 os conteudos de s1 e s2 respectivamente

// ft_getlen verifica e devolve o tamanho da string passada como ponteiro

// ft_calloc faz a alocacao da memoria em lugar do malloc pois
// ja preenche o conteudo com zeros
