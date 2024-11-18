/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:39:41 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/08 14:19:41 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cont;

	if (dst == NULL && src == NULL)
		return (NULL);
	cont = 0;
	while (cont < n)
	{
		((char *)dst)[cont] = ((char *)src)[cont];
		cont++;
	}
	return (dst);
}

/*int	main(void)
{
	char src[25] = "Esta es la funcion memcpy";
	char *dst;

	printf("%d", ft_memcpy(dst, src,  8));
}*/
