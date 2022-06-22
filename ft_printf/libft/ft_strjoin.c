/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:08:31 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/25 13:12:45 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (!(s1) && !(s2))
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(newstr))
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (newstr);
}
