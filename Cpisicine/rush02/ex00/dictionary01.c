/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:08:34 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 16:01:02 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary01.h"

int	ft_dict_add(t_dict *head, char *key, char *value)
{
	t_node	*temp;

	temp = head->root_node;
	if (head->count == 0)
	{
		temp = ft_new_node(key, value);
		head->root_node = temp;
	}
	else
	{
		while (temp)
		{
			if (ft_is_str_same(temp->key, key))
				return (0);
			if (!temp->next)
			{
				temp->next = ft_new_node(key, value);
				break ;
			}
			temp = temp->next;
		}
	}
	head->count++;
	return (1);
}

t_node	*ft_dict_getnode(t_dict *head, char *key)
{
	t_node	*found;

	found = head->root_node;
	while (found)
	{
		if (ft_is_str_same(found->key, key))
		{
			return (found);
		}
		found = found->next;
	}
	return (0);
}

char	*ft_dict_get_value(t_dict *head, char *key)
{
	t_node	*found_node;

	found_node = ft_dict_getnode(head, key);
	if (!found_node)
	{
		return (0);
	}
	return (found_node->value);
}
