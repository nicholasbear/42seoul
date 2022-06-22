/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:16:24 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/09 21:23:09 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	temp;

	temp = 0;
	if (str[temp] == '\0')
		return (1);
	while (str[temp])
	{	
		if (str[temp] > 'Z' || str[temp] < 'A')
			return (0);
		temp++;
	}
	return (1);
}
