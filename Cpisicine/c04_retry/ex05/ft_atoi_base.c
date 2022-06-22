/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:07:11 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/13 19:10:12 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char*str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}

int	check_error(char *base)
{
	int	temp;
	int	i;

	temp = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[temp])
	{
		if (base[temp] == '+' || base[temp] == '-')
			return (0);
		if (base[temp] < 32 || base[temp] > 126)
			return (0);
		i = 0;
		while (i < temp)
		{
			if (base[i] == base[temp])
				return (0);
			i++;
		}
		temp++;
	}
	return (1);
}

int	changenum(char*str, int num, char*base)
{
	int	i;
	int	start;
	int	res;

	i = 0;
	start = 0;
	res = 0;
	while (i < num)
	{
		start = 0;
		while (str[i] != base[start])
		{
			start++;
		}
		res = res * ft_strlen(base) + start;
		i++;
	}
	return (res);
}

int	ft_atoi(char*c, char*base)
{
	int	temp;
	int	i;

	temp = 0;
	while (1)
	{
		i = 0;
		while (i < ft_strlen(base))
		{
			if (c[temp] == base[i])
				break ;
			i++;
		}
		if (i == ft_strlen(base))
			return (temp);
		temp++;
	}	
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	last;
	int	num;
	int	minus;

	i = 0;
	minus = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	if (check_error(base) == 0)
		return (0);
	num = ft_atoi(&str[i], base);
	last = changenum(&str[i], num, base);
	if (minus % 2 == 1)
		last = -last;
	return (last);
}
