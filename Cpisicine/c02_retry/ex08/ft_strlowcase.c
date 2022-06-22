/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:33:40 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/09 21:33:58 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		if (str[temp] >= 'A' && str[temp] <= 'Z')
		{
			str[temp] += 32;
		}
		temp++;
	}
	return (str);
}
