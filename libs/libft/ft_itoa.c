/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:31:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/19 10:11:56 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_str(int size, int value)
{
	if (value < 0)
	{
		value *= -1;
		size++;
	}
	while (value != 0 && size++ >= 0)
		value = value / 10;
	return (size);
}

static void	write_str(char *str, size_t size, int value)
{
	if (value < 0)
	{
		value *= -1;
	}
	str[size] = '\0';
	while (size--)
	{
		str[size] = (value % 10) + 48;
		value = value / 10;
		if (str[0] == '0')
			str[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		value;
	size_t	size;

	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	value = n;
	size = size_str(size, value);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	write_str(str, size, value);
	return (str);
}

/*int	main(void)
{
	char	*str;

	str = ft_itoa(2147483648);
	printf("%s\n", str);
}*/
