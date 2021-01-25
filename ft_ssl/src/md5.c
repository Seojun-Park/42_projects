/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:19:52 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 21:35:30 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int	g_md5_s[64] =
{
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

unsigned int	g_md5_k[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static void		md5_loop(int i, t_md *md)
{
	if (0 <= i && i <= 15)
	{
		md->f = (md->b & md->c) | ((~md->b) & md->d);
		md->g = i;
	}
	else if (16 <= i && i <= 31)
	{
		md->f = (md->d & md->b) | ((~md->d) & md->c);
		md->g = (5 * i + 1) % 16;
	}
	else if (32 <= i && i <= 47)
	{
		md->f = md->b ^ md->c ^ md->d;
		md->g = (3 * i + 5) % 16;
	}
	else
	{
		md->f = md->c ^ (md->b | (~md->d));
		md->g = (7 * i) % 16;
	}
	md->f = md->f + md->a + g_md5_k[i] + *((unsigned int *)(md->mem[md->g]));
	md->a = md->d;
	md->d = md->c;
	md->c = md->b;
	md->b = md->b + left_rotate(md->f, g_md5_s[i]);
}

static void		md5_oper(int i, t_md *md)
{
	int index;
	int j;

	index = -1;
	while (++index < 16)
	{
		j = -1;
		while (++j < 4)
			md->mem[index][j] = md->msg[i * 64 + index * 4 + j];
	}
	md->a = md->A;
	md->b = md->B;
	md->c = md->C;
	md->d = md->D;
	index = -1;
	while (++index < 64)
		md5_loop(index, md);
	md->A += md->a;
	md->B += md->b;
	md->C += md->c;
	md->D += md->d;
}

static void		md5_set(char *s, t_md *md)
{
	int			i;
	uint64_t	len;

	md->A = PRE_A;
	md->B = PRE_B;
	md->C = PRE_C;
	md->D = PRE_D;
	len = 0;
	if (s != NULL)
		md->set = (ft_strlen(s) + 8) / 64 + 1;
	else
		md->set = 1;
	md->msg = (unsigned char *)malloc(64 * md->set);
	i = -1;
	while (++i < (int)(64 * md->set))
		md->msg[i] = 0;
	i = -1;
	while (s && s[++i])
		md->msg[i] = s[i];
	md->msg[i == -1 ? 0 : i] = 1 << 7;
	len = i << 3;
	i = -1;
	while (++i < 8)
		md->msg[64 * md->set - 8 + i] = len >> (i * 8);
}

void			ft_md5(char *s)
{
	t_md	md;
	int		i;

	i = -1;
	ft_bzero(&md, 10);
	md5_set(s, &md);
	while (++i < (int)(md.set))
		md5_oper(i, &md);
	byte_rev(&md.A);
	byte_rev(&md.B);
	byte_rev(&md.C);
	byte_rev(&md.D);
	ft_printf("%.8x%.8x%.8x%.8x", md.A, md.B, md.C, md.D);
	free(md.msg);
}
