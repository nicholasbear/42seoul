/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:55:16 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/10 12:37:22 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	if_word(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	capital(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char	low(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = -1;
	first = 1;
	while (str[++i])
	{	
		if (first == 1)
		{
			if (if_word(str[i]) == 1)
			{
				str[i] = capital(str[i]);
				first = 0;
			}
		}
		else
		{
			if (if_word(str[i]) == 0)
				first = 1;
			else
				str[i] = low(str[i]);
		}
	}
	return (str);
}
