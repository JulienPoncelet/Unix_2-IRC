/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:19:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:35:41 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include				<arpa/inet.h>
# include				<error.h>
# include				<get_next_line.h>
# include				<libft.h>
# include				<ncurses.h>
# include				<netdb.h>
# include				<netinet/in.h>
# include				<stdio.h>
# include				<sys/stat.h>
# include				<sys/time.h>

# define C_USAGE		"usage: client <host> <port>"

# define YPP(y, max)	((y < max) ? y++ : y)

# define DOMAIN			PF_INET
# define FAMILY			AF_INET
# define TYPE			SOCK_STREAM

# define SIZE			4096

enum					e_type
{
	MSG, NICK, JOIN, LEAVE, CREATE, LIST, WHO, MP, QUIT, WRONG
};

# define TYPE_ENUM		{MSG, NICK, JOIN, LEAVE, CREATE, LIST, WHO, MP, WRONG}
# define CMD	{"/nick", "/join", "/leave", "/create", "/list", "/who", "/msg"}
# define TYPE_FUNCT		{msg, nick, join, leave, create, list, who, mp, wrong}
# define TYPE_SIZE		9

typedef struct			s_client
{
	WINDOW				*win;
	int					sd;
	fd_set				fd_read;
	char				*addr;
	int					port;
	char				*nick;
	int					x;
	int					y;
	int					curx;
	int					maxy;
	char				*buf;
	char				*line;
}						t_client;

/*
**						ncurse.c
*/

void					init_ncurse(t_client *client);

/*
**						check_input.c
*/

int						check_input(int ac, char ***av);

/*
**						t_client.c
*/

t_client				*init_client(char *addr, int port);
void					end_client(t_client *client);

/*
**						ft socket's functions
*/

int						ft_connect(int sd, char *addr, int port);
int						ft_socket(void);

/*
**						loop.c
*/

void					loop_client(t_client *client);
void					print_prompt(t_client *client);
char					*wrong(t_client *client);
void					put_error(t_client *client, char *error);

/*
**						getnexttype.c
*/

int						getnexttype(int sson, char **line, t_client *client);
char					*use_key(int key, char *buf, t_client *client);
char					*add_to_buf(char *buf, int i, int key);
char					*del_from_buf(char *buf, int i);
char					*get_next_cmd(t_client *client);
int						get_type(char *cmd);

/*
**						select.c
*/

void					init_select(t_client *client);
int						ft_select(t_client *client);
void					read_msg(t_client *client);

/*
**						add_ch.c
*/

int						add_ch(t_client *client);

/*
**						msg
*/

char					*msg(t_client *client);

/*
**						nickname
*/

char					*nick(t_client *client);

/*
**						channel
*/

char					*join(t_client *client);
char					*create(t_client *client);
char					*leave(t_client *client);
char					*list(t_client *client);

/*
**						who
*/

char					*who(t_client *client);

/*
**						mp
*/

char					*mp(t_client *client);

#endif
