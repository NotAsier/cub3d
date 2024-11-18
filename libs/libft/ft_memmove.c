/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:03:25 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/26 13:30:02 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned const char	*src1;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dst1 = dst;
	src1 = src;
	if (dst1 > src1)
	{
		while (len--)
		{
			dst1[len] = src1[len];
		}
	}
	else if (dst1 < src1)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*int main(void)
{
    char *s1 = "hola me llamo asier";
	char *s2 = "llamo";
	size_t n = 13;
	printf("%s \n",ft_memmove(s1, s2, n));
}*/
