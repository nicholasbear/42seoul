/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary00.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:55:10 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 15:57:28 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY00_H
# define DICTIONARY00_H
# include "utilstr.h"
# include <stdlib.h>

typedef struct s_node
{
	char			key[50];
	char			value[50];
	struct s_node	*next;
}t_node;

typedef struct s_dictionary
{
	int				count;
	struct s_node	*root_node;
}t_dict;

t_node	*ft_new_node(char *key, char *value);
t_dict	*ft_new_dict(void);
void	ft_dict_free(t_dict *head);
#endif
