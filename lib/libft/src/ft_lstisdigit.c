/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstisdigit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:49 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:30:41 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstisdigit(const t_list *list)
{
	const t_list	*lst;

	lst = list;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (ft_strisdigit(lst->content) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}
