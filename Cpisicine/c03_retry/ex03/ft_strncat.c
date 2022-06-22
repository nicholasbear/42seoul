/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:24:29 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/10 16:23:05 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				temp;
	unsigned int	tmp;

	temp = 0;
	tmp = 0;
	while (dest[temp])
	{
		temp++;
	}
	while (tmp < nb && src[tmp])
	{
		dest[temp] = src[tmp];
		temp++;
		tmp++;
	}
	dest[temp] = '\0';
	return (dest);
}
