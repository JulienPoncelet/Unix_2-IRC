/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 15:33:57 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:01:12 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int							ft_accept(int sd)
{
	int						cs;
	struct sockaddr_in		csin;
	unsigned int			clen;

	if ((cs = accept(sd, (struct sockaddr *)&csin, &clen)) == -1)
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (FT_ERROR);
	}
	return (cs);
}
