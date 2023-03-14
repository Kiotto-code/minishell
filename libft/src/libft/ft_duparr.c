/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:45:05 by yichan            #+#    #+#             */
/*   Updated: 2023/03/14 00:45:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_duparr(char **arr)
{
	char	**ret;
	int		arr_len;

	if (!arr)
		return (NULL);
	arr_len = ft_arrind(arr);
	ret = malloc(sizeof(char *) * (arr_len + 1));
	ret[arr_len] = 0;
	while (arr_len-- >= 0)
		ret[arr_len] = ft_strdup(arr[arr_len]);
	return (ret);
}
