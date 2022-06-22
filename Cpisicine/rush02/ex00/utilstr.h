/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:53:37 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 16:00:42 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSTR_H
# define UTILSTR_H
# include <unistd.h>
int		ft_is_str_same(char *str1, char *str2);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_strcpy(char *dst, char *src);
#endif
