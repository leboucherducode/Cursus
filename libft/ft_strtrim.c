/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:03:30 by jeschwar          #+#    #+#             */
/*   Updated: 2024/10/28 10:15:40 by jeschwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	end = ft_strlen((char *)s1);
	start = 0;
	while (ft_strchr(set, s1[start]) != 0 && start < end)
		start++;
	while (ft_strchr(set, s1[end - 1]) != 0 && end - start > 0)
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1 + start, end - start);
	str[end - start] = '\0';
	return (str);
}
