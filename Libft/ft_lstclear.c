/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 00:32:54 by bypark            #+#    #+#             */
/*   Updated: 2021/05/10 17:04:15 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		target = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = target;
	}
	*lst = 0;
}
