/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr2lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:37:49 by yichan            #+#    #+#             */
/*   Updated: 2023/02/24 15:11:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void (*ft_lstadd_back)(t_list **lst, t_list *new)

int	ft_arr2lst(void **lst, char **arr, \
	void (*add_back)(void **lst, void *new))
{
	int	i;
	int	arr_len;

	if (!lst || !arr || !add_back)
		return (0);
	i = -1;
	arr_len = ft_arrind(arr);
	while (++i < arr_len)
	{
		add_back(lst, ft_lstnew(arr[i]));
	}
	
}