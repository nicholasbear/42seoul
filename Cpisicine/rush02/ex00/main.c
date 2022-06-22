/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:28:24 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 20:56:28 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utildictionary.h"

void	try_open_dict(t_dict *dict, char *dict_path, char *key)
{
	char	buffer[100];

	if (!ft_try_parse(key, buffer))
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (ft_open(dict, dict_path))
	{
		ft_convert(buffer, dict);
		ft_putchar('\n');
		return ;
	}
	write(2, "Dict Error\n", 11);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	int		rslt;

	rslt = 0;
	dict = ft_new_dict();
	if (argc == 2)
	{
		try_open_dict(dict, "numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		try_open_dict(dict, argv[1], argv[2]);
	}
	else
	{
		write(2, "Error\n", 6);
		rslt = 1;
	}
	ft_dict_free(dict);
	return (rslt);
}
