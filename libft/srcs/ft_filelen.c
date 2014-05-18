/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 12:07:33 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:08:35 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int							ft_filelen(int fd)
{
	int						len;
	char					buf[1];

	len = 0;
	while (read(fd, buf, 1))
		len++;
	close(fd);
	return (len);
}
