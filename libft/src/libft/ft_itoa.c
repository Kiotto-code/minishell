/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:31 by yichan            #+#    #+#             */
/*   Updated: 2022/07/10 17:41:39 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		i;
	long int	nb;

	nb = n;
	i = count(nb);
	if (n < 0)
	{
		nb = -nb;
		i += 1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i--)
	{
		res[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
