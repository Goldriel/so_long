/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:12:13 by jarrakis          #+#    #+#             */
/*   Updated: 2022/01/25 21:13:33 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

static char	**ft_free_str(char **split, unsigned int len)
{
	while (len > 0)
	{
		free(split[len - 1]);
		len--;
	}
	free(split);
	return (NULL);
}

static void	ft_next_str(char **str, unsigned int *len, char c)
{
	unsigned int	i;

	*str += *len;
	*len = 0;
	i = 0;
	while (**str && (**str == c))
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static unsigned int	ft_count_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count_str;

	if (!s[0])
		return (0);
	i = 0;
	count_str = 0;
	while (s[i] != '\0' && (s[i] == c))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count_str++;
			while (s[i] && (s[i] == c))
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		count_str++;
	return (count_str);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	len;
	unsigned int	count_str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	count_str = ft_count_str(s, c);
	split = (char **)malloc(sizeof(char *) * (count_str + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (i < count_str)
	{
		ft_next_str((char **)&s, &len, c);
		split[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (split[i] == NULL)
			return (ft_free_str(split, i));
		ft_strlcpy(split[i], (char *)s, len + 1);
		i++;
	}
	split[i] = NULL;
	return (split);
}