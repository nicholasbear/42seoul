/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utildictionary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:33:27 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 20:45:58 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utildictionary.h"

int	ft_try_parse(char *str, char *outbuffer)
{
	char	zero[2];
	int		iter;

	zero[0] = '0';
	zero[1] = '\0';
	iter = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[iter])
	{
		if (!('0' <= str[iter] && str[iter] <= '9'))
			return (0);
		iter++;
	}
	str[iter] = '\0';
	ft_strcpy(outbuffer, str);
	return (1);
}
