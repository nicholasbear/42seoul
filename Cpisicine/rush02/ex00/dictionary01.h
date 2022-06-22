/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary01.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:08:40 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 15:57:35 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY01_H
# define DICTIONARY01_H
# include "dictionary00.h"
int		ft_dict_add(t_dict *head, char *key, char *value);
t_node	*ft_dict_getnode(t_dict *head, char *key);
char	*ft_dict_get_value(t_dict *head, char *key);
#endif
