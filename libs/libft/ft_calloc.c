/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:13:41 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/26 13:04:09 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	str = malloc(size * count);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
