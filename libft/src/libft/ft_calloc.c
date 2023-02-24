/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:40:38 by yichan            #+#    #+#             */
/*   Updated: 2022/07/11 14:36:07 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	len;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (NULL);
	len = count * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, size * count);
	return (ptr);
}
