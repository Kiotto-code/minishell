/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:27:42 by yichan            #+#    #+#             */
/*   Updated: 2023/03/09 01:46:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strend(char *str, int n)
{
	return (str + (strlen(str) - n));
}

int main()
{
	char *s = "hello";
	char *ret = ft_strend(s, strlen(s) -1);
	printf("%s", ret);
}