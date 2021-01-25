/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:33:51 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 21:28:03 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../library/libft/libft.h"

# include <math.h>
# define LEFT_SHIFT num << 8

# define PRE_A 0x67452301
# define PRE_B 0xefcdab89
# define PRE_C 0x98badcfe
# define PRE_D 0x10325476

typedef struct	s_flags
{
	int			p;
	int			q;
	int			r;
	int			s;
}				t_flags;

typedef struct	s_fp
{
	char		*command;
	void		(*function)(char *);
}				t_fp;

typedef struct	s_ssl
{
	t_fp		dp;
	t_flags		flags;
}				t_ssl;

typedef struct	s_md
{
	unsigned int	A;
	unsigned int	B;
	unsigned int	C;
	unsigned int	D;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	f;
	unsigned int	g;
	unsigned int	set;
	unsigned char	*msg;
	unsigned char	mem[16][4];
}				t_md;

typedef struct	s_sha
{
	unsigned int	hash[8];
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	set;
	unsigned char	*msg;
	unsigned int	mem[64];
}				t_sha;

typedef struct	s_sha512
{
	uint64_t		hash[8];
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
	uint64_t		set;
	unsigned char	*msg;
	uint64_t		mem[80];	
}				t_sha512;


void			ft_md5(char *s);
void			byte_rev(unsigned int *c);
void			get_file(int fd, char *file_name, t_ssl *ssl);
void			get_flags(int i, int argc, char **argv, t_ssl *ssl);
void			print_by_flags(int i, char **argv, t_ssl *ssl);
void			go_here(int i, char **argv, t_ssl *ssl);
void			error_sign(int i, char *argv, t_ssl *ssl);
void			error_message(char *argv);
void			error_usage(void);
unsigned int	left_rotate(unsigned int x, unsigned int c);
unsigned int	right_rotate(unsigned int x, unsigned int c);
unsigned int	right_rotate_64(unsigned int x, unsigned int c);
void			ft_sha256(char *s);
void			ft_sha224(char *s);
void			ft_sha512(char *s);
static void		sha224_ready(int i, t_sha *sha);
static void		sha224_set(char *s, t_sha *sha);
static void		sha224_shift(int i, t_sha *sha);
static void		sha224_loop(int i, t_sha *sha);
static void		sha512_ready(int i, t_sha512 *sha);
static void		sha512_set(char *s, t_sha512 *sha);
static void		sha512_shift(int i, t_sha512 *sha);
static void		sha512_loop(int i, t_sha512 *sha);
static void		sha256_shift(int i, t_sha *sha);
static void		sha256_loop(int i, t_sha *sha);

static t_fp g_ssl_dp[] =
{
	{"md5", ft_md5},
	{"sha256", ft_sha256},
	{"sha224", ft_sha224},
	{"sha512", ft_sha512},
	{NULL, NULL}
};

#endif
