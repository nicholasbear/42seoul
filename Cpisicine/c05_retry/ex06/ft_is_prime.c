/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:43 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/11 14:40:23 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	temp;
	int	num;

	temp = 2;
	num = 0;
	if (nb < 2)
		return (0);
	while (temp < nb)
	{
		if (nb % temp == 0)
			num++;
		temp++;
	}
	if (num == 0)
		return (1);
	else
		return (0);
}
