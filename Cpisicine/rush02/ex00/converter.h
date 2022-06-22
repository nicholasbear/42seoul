/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:23:54 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 15:58:06 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H
# include "utilfile.h"
char	*ft_maketmp(char *temp, int length);
void	ft_longword(char *str, t_dict *dic, int length);
void	ft_hundred(char *str, t_dict *dic);
void	ft_ten(char *str, t_dict *dic);
void	ft_convert(char *str, t_dict *dic);
#endif
