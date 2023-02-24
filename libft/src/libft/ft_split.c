/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:36:20 by yichan            #+#    #+#             */
/*   Updated: 2022/07/10 16:53:41 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**setup(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	split = setup(s, c);
	if (!split)
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		while (s[start] == c)
			start ++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_substr(s, start, (end - start));
		start = end;
		i++;
	}
	split[i] = 0;
	return (split);
}
