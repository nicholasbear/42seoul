/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:55:28 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 15:57:24 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary00.h"

t_node	*ft_new_node(char *key, char *value)
{
	t_node	*rslt;

	rslt = (t_node *)malloc(sizeof(t_node));
	ft_strcpy(rslt->key, key);
	ft_strcpy(rslt->value, value);
	rslt->next = 0;
	return (rslt);
}

t_dict	*ft_new_dict(void)
{
	t_dict	*rslt;

	rslt = (t_dict *)malloc(sizeof(t_dict));
	rslt->root_node = 0;
	rslt->count = 0;
	return (rslt);
}

void	ft_dict_free(t_dict *head)
{
	t_node	*temp;
	t_node	*crnt;

	crnt = head->root_node;
	while (crnt)
	{
		temp = crnt->next;
		free(crnt);
		crnt = temp;
	}
	free(head);
}
