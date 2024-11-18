/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:22:03 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/26 13:52:36 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	size_t	len;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	i = (ft_strlen(s1));
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str1 = malloc(sizeof(char) * (len));
	if (str1 == NULL || (str1 == NULL && s2 == NULL))
		return (NULL);
	ft_strlcpy(str1, s1, len);
	while (i <= len && s2[k])
	{
		str1[i] = s2[k];
		i++;
		k++;
	}
	str1[i] = '\0';
	return (str1);
}
