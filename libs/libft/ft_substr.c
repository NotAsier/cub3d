/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:20:51 by aarranz-          #+#    #+#             */
/*   Updated: 2023/05/26 14:07:42 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	length;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	length = len;
	i = start;
	k = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) <= len)
		length = ft_strlen(s + start);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (length-- && s[i])
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_substr("asierarranz", 4, 3));
}*/
