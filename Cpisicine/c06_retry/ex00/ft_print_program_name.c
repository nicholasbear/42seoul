/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:14:47 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/11 19:42:30 by wookim2          ###   ########.fr       */
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

	temp = 0;
	(void)argc;
	while (argv[0][temp])
	{
		ft_putchar(argv[0][temp]);
		temp++;
	}
	ft_putchar('\n');
	return (0);
}
