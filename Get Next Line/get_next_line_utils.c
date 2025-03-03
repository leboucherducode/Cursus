/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <jeschwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:10:16 by jeschwar          #+#    #+#             */
/*   Updated: 2024/12/05 10:05:11 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start >= i)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;

	size_s1 = 0;
	size_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[size_s1] != '\0')
		size_s1++;
	while (s2[size_s2] != '\0')
		size_s2++;
	str = (char *)malloc(size_s1 + size_s2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy (str, s1, size_s1);
	ft_memcpy (str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = '\0';
	return (str);
}
