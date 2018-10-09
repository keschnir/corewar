/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_toupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:31 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:31 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
	{
		if (c >= 'a' && c <= 'z')
		{
			c = c - 'a' + 'A';
		}
	}
	return (c);
}
