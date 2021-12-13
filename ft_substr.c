/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:57:50 by thpham-v          #+#    #+#             */
/*   Updated: 2021/12/13 05:25:46 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start > slen)
		start = (unsigned int)slen;
	if (start + len > slen)
		len = slen - start;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_memmove(res, s + start, len);
	res[len] = '\0';
	return (res);
}
