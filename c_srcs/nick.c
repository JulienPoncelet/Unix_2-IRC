/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:47:50 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char						*nick(t_client *client)
{
	char					**split;

	split = ft_strsplit(client->line, " ");
	if (!split[1])
		return (NICK_ARG);
//	send split 1;
	return (0);
}
