/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:37:52 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 16:00:52 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILFILE_H
# define UTILFILE_H
# include <fcntl.h>
# include "dictionary01.h"
int	ft_open(t_dict *out_dict, char *new_dict);
int	ft_getval(char *buffer);
#endif
