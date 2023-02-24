/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:50 by yichan            #+#    #+#             */
/*   Updated: 2022/07/06 21:52:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	modlen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	modlen = ft_strlen(s + start);
	if (modlen < len)
		len = modlen;
	substr = malloc(sizeof(char) * len +1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len +1);
	return (substr);
}
