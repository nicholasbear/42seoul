/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:18:03 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/09 21:24:32 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	temp;

	temp = 0;
	if (str[temp] == '\0')
		return (1);
	while (str[temp])
	{	
		if (str[temp] > 126 || str[temp] < 32)
			return (0);
		temp++;
	}
	return (1);
}
