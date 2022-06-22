/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:40:48 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/26 16:35:59 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num(char const *s, char c)
{
	int	i;
	int	num;

	if (!(s))
		return (0);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			num++;
			if (i == 0)
				num--;
			if (s[i + 1] == c)
				num--;
		}
		i++;
	}
	if (s[i - 1] != c)
		num++;
	return (num);
}

int	get_string(char const *s, char *temp, char c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		temp[j] = s[i];
		j++;
	}
	temp[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	int				i;
	int				place;
	int				num;

	num = get_num(s, c);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (!res || num == 0)
		return (NULL);
	i = 0;
	place = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i += get_string(&s[i], res[place], c);
			place++;
		}
		else
			i++;
	}
	res[num] = NULL;
	return (res);
}
