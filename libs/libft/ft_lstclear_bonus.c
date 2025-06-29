/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:04:44 by msidry            #+#    #+#             */
/*   Updated: 2024/11/07 20:26:33 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reco_clear(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || *lst == NULL || !del)
		return ;
	ft_reco_clear(*lst, del);
	*lst = NULL;
}

static	void	ft_reco_clear(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		ft_reco_clear(lst->next, del);
	del(lst->content);
	free(lst);
}
