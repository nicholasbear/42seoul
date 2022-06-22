/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:15:25 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/17 16:43:24 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	num = nb;
	while (--nb > 0)
	{
		num = num * nb;
	}
	return (num);
}
