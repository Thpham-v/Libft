/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:00:26 by thpham-v          #+#    #+#             */
/*   Updated: 2021/12/13 05:28:35 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	start;
	size_t	end;

	newstr = NULL;
	if (!set && s1)
		newstr = ft_strdup(s1);
	else if (s1)
	{
		start = 0;
		end = ft_strlen(s1);
		if (end == ft_strlen(s1))
			end--;
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end >= 0 && ft_strchr(set, s1[end]))
			end--;
		newstr = ft_substr(s1, start, (end - start + 1));
	}
	return (newstr);
}
