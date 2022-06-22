/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:15:21 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/08 19:27:40 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	temp;

	temp = 0;
	if (str[temp] == '\0')
		return (1);
	while (str[temp])
	{	
		if (str[temp] > '9' || str[temp] < '0')
			return (0);
		temp++;
	}
	return (1);
}
