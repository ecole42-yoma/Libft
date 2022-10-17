/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_ctype_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:52:15 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/08 14:52:18 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = 'A' + (c - 'a');
	return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = 'a' + (c - 'A');
	return (c);
}
