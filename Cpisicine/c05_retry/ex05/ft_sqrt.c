/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:08:34 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/17 11:22:40 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	num;
	unsigned int	nb1;

	num = 0;
	if (nb <= 0)
		return (0);
	nb1 = nb;
	while (num * num <= nb1)
	{
		if (num * num == nb1)
			return (num);
		num++;
	}
	return (0);
}
