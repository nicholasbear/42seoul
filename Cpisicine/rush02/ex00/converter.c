/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:23:58 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 20:55:28 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

char	*ft_maketemp(char *temp, int length)
{
	int	j;

	temp[0] = '1';
	j = 0;
	while (++j < length - 1)
		temp[j] = '0';
	temp[j] = '\0';
	return (temp);
}

void	ft_longword(char *str, t_dict *dic, int	length)
{
	int		i;
	char	c[4];
	char	*temp;

	i = 0;
	while ((length - i) % 3 != 1)
	{
		c[i] = str[i];
		i++;
	}
	c[i] = str[i];
	c[i + 1] = '\0';
	temp = (char *)malloc(sizeof(char) * (length - i + 1));
	ft_convert(c, dic);
	ft_putchar(' ');
	ft_putstr(ft_dict_get_value(dic, ft_maketemp(temp, length - i + 1)));
	free(temp);
	while (str[i + 1] == '0')
		i++;
	if (str[i + 1] != '\0')
	{
		ft_putchar(' ');
		ft_convert(&str[i + 1], dic);
	}
}

void	ft_hundred(char *str, t_dict *dic)
{
	char	c;

	c = str[0];
	ft_putstr(ft_dict_get_value(dic, &c));
	ft_putchar(' ');
	ft_putstr(ft_dict_get_value(dic, "100"));
	if (str[1] == '0')
	{
		if (str[2] != '0')
		{
			ft_putchar(' ');
			ft_convert(&str[2], dic);
		}
	}
	else
	{
		ft_putchar(' ');
		ft_convert(&str[1], dic);
	}
}

void	ft_ten(char *str, t_dict *dic)
{
	char	c[3];

	if (str[0] == '1')
		ft_putstr(ft_dict_get_value(dic, str));
	else
	{
		if (str[1] == '0')
			ft_putstr(ft_dict_get_value(dic, &str[0]));
		else
		{
			c[0] = str[0];
			c[1] = '0';
			c[2] = '\0';
			ft_putstr(ft_dict_get_value(dic, c));
			ft_putchar(' ');
			ft_putstr(ft_dict_get_value(dic, &str[1]));
		}
	}
}

void	ft_convert(char *str, t_dict *dic)
{
	int	length;

	if (str[0] == '\0')
		return ;
	length = ft_strlen(str);
	if (length >= 40)
		write(2, "Dict Error", 10);
	else if (length >= 4)
		ft_longword(str, dic, length);
	else if (length == 3)
		ft_hundred(str, dic);
	else if (length == 2)
		ft_ten(str, dic);
	else
		ft_putstr(ft_dict_get_value(dic, str));
}
