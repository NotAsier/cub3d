/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:23:07 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/03 21:57:01 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	conpare_left(char *str, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (str[i] != set[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (i);
}

static char	conpare_right(char *str, char *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str);
	j = 0;
	while (set[j])
	{
		if (str[i - 1] != set[j])
			j++;
		else
		{
			j = 0;
			i--;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	i2;

	if (!s1 || !set)
		return (NULL);
	i = conpare_left((char *)s1, (char *)set);
	i2 = conpare_right((char *)s1, (char *)set);
	str = ft_substr(s1, i, i2 - i);
	if (!str)
		return (NULL);
	return (str);
}
/* 
int	main(void)
{
	printf("%s", ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "));
} */
