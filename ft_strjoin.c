/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:28:12 by thpham-v          #+#    #+#             */
/*   Updated: 2021/01/14 17:19:26 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	size_t	alllen;
	char	*newstr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	alllen = s1len + s2len;
	if (!(newstr = malloc(sizeof(char) * alllen + 1)))
		return (NULL);
	ft_memcpy(newstr, s1, s1len);
	ft_memcpy(&newstr[s1len], s2, s2len);
	newstr[alllen] = '\0';
	return (newstr);
}
