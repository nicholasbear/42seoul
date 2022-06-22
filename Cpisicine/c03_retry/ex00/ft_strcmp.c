/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:45:10 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/09 20:21:36 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	temp;

	temp = 0;
	while (s1[temp] && s2[temp])
	{
		if (s1[temp] < s2[temp])
			return (-1);
		if (s1[temp] > s2[temp])
			return (1);
		temp++;
	}
	if (s1[temp] == '\0')
	{
		if (s2[temp] == '\0')
			return (0);
		else
			return (-1);
	}
	return (1);
}
