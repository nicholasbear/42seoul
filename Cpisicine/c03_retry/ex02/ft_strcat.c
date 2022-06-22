/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:55:49 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/10 16:20:58 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	temp;
	int	tmp;

	temp = 0;
	tmp = 0;
	while (dest[temp])
	{
		temp++;
	}
	while (src[tmp])
	{
		dest[temp] = src[tmp];
		temp++;
		tmp++;
	}
	dest[temp] = '\0';
	return (dest);
}
