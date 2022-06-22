/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:37:42 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 21:34:33 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilfile.h"

int	ft_getval(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	j = i;
	while (buffer[i] == ':' || buffer[i] <= 32)
		i++;
	buffer[j] = '\0';
	return (i);
}

int	ft_open(t_dict *out_dict, char *new_dict)
{
	int		rslt;
	char	bff[200];
	int		i;
	char	oneletter;

	rslt = open(new_dict, O_RDONLY);
	if (rslt < 0)
		return (0);
	i = -1;
	while (read(rslt, &oneletter, 1) > 0)
	{
		if (oneletter == '\n')
		{
			bff[++i] = '\0';
			if (i != 0 && !ft_dict_add(out_dict, &bff[0], &bff[ft_getval(bff)]))
				return (0);
			i = -1;
		}
		else
			bff[++i] = oneletter;
	}
	close(rslt);
	return (1);
}
