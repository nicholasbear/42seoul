/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:37:18 by wookim2           #+#    #+#             */
/*   Updated: 2022/07/03 16:46:46 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(char const *s, ...);
int	printf_c(va_list ap);
int	printf_s(va_list ap);
int	printf_p(va_list ap);
int	printf_di(va_list ap);
int	printf_u(va_list ap);
int	printf_x(va_list ap);
int	printf_bigx(va_list ap);
int	printf_obelus(void);

#endif
