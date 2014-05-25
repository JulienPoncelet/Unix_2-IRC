/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:43:05 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:46:15 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NICK_ARG			"nick: need 1 argument, 0 given."
# define NICK_USE			"nick: nickname already used."
# define NICK_LEN			"nick: nickname can't take more than 9 character."

# define JOIN_ARG			"join: need 1 argument, 0 given."
# define JOIN_USE			"join: this channel doesn't exist."

# define LEAVE_HOME			"leave: you can't leave the Home channel."

# define CREATE_ARG			"creat: need 1 argument, 0 given."
# define CREATE_USE			"create: channel already exist."

# define MP_ARG				"msg: need 2 arguments."
# define MP_NICK			"msg: this nickname doesn't exist."

#endif
