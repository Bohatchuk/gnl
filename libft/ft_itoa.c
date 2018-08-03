/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:16:10 by dbohatch          #+#    #+#             */
/*   Updated: 2017/11/16 21:51:19 by dbohatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = get_size(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	i = len - 1;
	while (n && i >= 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	str[len] = '\0';
	return (str);
}
