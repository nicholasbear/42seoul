/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:17:33 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/12 19:52:26 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	temp;

	temp = 0;
	while (s1[temp] && s2[temp])
	{
		if (s1[temp] < s2[temp])
			return (-1);
		if (s1[temp] > s2[temp])
			return (1);
		temp++;
	}
	if (s1[temp] == '\0')
	{
		if (s2[temp] == '\0')
			return (0);
		else
			return (-1);
	}
	return (1);
}

void	sort(int num, char *argv[])
{
	int		i;
	int		temp;
	char	*a;

	i = 2;
	while (i < num)
	{
		temp = 1;
		a = argv[i];
		while (temp < i)
		{
			if (ft_strcmp(argv[temp], argv[i]) > 0)
			{
				a = argv[temp];
				argv[temp] = argv[i];
				argv[i] = a;
			}
			temp++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	temp;
	int	i;

	sort(argc, argv);
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
