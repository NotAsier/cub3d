/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:28:53 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/03 11:38:37 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_c;
	size_t	src_c;
	size_t	i;

	i = 0;
	src_c = ft_strlen(src);
	dst_c = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= dst_c)
	{
		return (dstsize + src_c);
	}
	while (i < (dstsize - dst_c - 1) && src[i])
	{
		dst[dst_c + i] = src[i];
		i++;
	}
	dst[dst_c + i] = '\0';
	return (dst_c + src_c);
}

/*int main(void)
{
	char *s1 ="Me llamo asier";
	char *s2 =" arranz";
	//printf("%lu",ft_strlcat(s1, s2, 5));
		printf("%lu",ft_strlcat(s1, s2, 5));
}*/