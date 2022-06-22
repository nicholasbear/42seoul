/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:45:45 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/10 21:27:20 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	temp;

	temp = 0;
	while (temp < n && src[temp])
	{
		dest[temp] = src[temp];
		temp++;
	}
	while (temp < n)
	{
		dest[temp] = '\0';
		temp++;
	}
	return (dest);
}
