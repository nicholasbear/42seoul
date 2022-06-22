/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:13:41 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/15 16:02:12 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	temp;
	int	i;

	temp = argc - 1;
	while (temp >= 1)
	{	
		i = 0;
		while (argv[temp][i])
		{
			ft_putchar(argv[temp][i]);
			i++;
		}
		ft_putchar('\n');
		temp--;
	}
	return (0);
}
