/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib_util_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:52:57 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/19 20:22:50 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	temp[3];
	void	*f_temp;

	if (!lst || !f)
		return (NULL);
	temp[head].next = NULL;
	while (lst)
	{
		f_temp = f(lst->content);
		temp[fresh].next = ft_lstnew(f_temp);
		if (!temp[fresh].next)
		{
			free(f_temp);
			ft_lstclear(&temp[head].next, del);
			return (NULL);
		}
		if (!temp[head].next)
			temp[head].next = temp[fresh].next;
		else
			temp[follow].next->next = temp[fresh].next;
		temp[follow].next = temp[fresh].next;
		lst = lst->next;
	}
	return (temp[head].next);
}
