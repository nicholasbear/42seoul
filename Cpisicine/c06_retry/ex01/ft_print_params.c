/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:37:49 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/12 19:13:03 by wookim2          ###   ########.fr       */
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

	temp = 1;
	while (temp < argc)
	{	
		i = 0;
		while (argv[temp][i])
		{
			ft_putchar(argv[temp][i]);
			i++;
		}
		ft_putchar('\n');
		temp++;
	}
	return (0);
}
