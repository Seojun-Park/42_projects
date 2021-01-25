/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:16:03 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 21:36:48 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int	g_sha256_k[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

unsigned int	g_sha256_v[8] =
{
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c,
	0x1f83d9ab, 0x5be0cd19
};

static void		sha256_loop(int i, t_sha *sha)
{
	unsigned int	s0;
	unsigned int	s1;
	unsigned int	temp1;
	unsigned int	ch;
	unsigned int	maj;

	s1 = right_rotate(sha->e, 6) ^ right_rotate(sha->e, 11) ^
		right_rotate(sha->e, 25);
	ch = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	temp1 = sha->h + s1 + ch + g_sha256_k[i] + sha->mem[i];
	s0 = right_rotate(sha->a, 2) ^ right_rotate(sha->a, 13) ^
		right_rotate(sha->a, 22);
	maj = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
	sha->h = sha->g;
	sha->g = sha->f;
	sha->f = sha->e;
	sha->e = sha->d + temp1;
	sha->d = sha->c;
	sha->c = sha->b;
	sha->b = sha->a;
	sha->a = temp1 + s0 + maj;
}

static void		sha256_shift(int i, t_sha *sha)
{
	int				index;
	int				j;
	unsigned int	sp1;
	unsigned int	sp2;

	index = -1;
	while (++index < 16)
	{
		j = -1;
		sha->mem[index] = 0;
		while (++j < 4)
			sha->mem[index] += sha->msg[i * 64 + index * 4 + j]
				<< (8 * (3 - j));
	}
	index = 15;
	while (++index < 64)
	{
		sp1 = right_rotate(sha->mem[index - 15], 7) ^
			right_rotate(sha->mem[index - 15], 18) ^
			(sha->mem[index - 15] >> 3);
		sp2 = right_rotate(sha->mem[index - 2], 17) ^
			right_rotate(sha->mem[index - 2], 19) ^
			(sha->mem[index - 2] >> 10);
		sha->mem[index] = sha->mem[index - 16]
			+ sp1 + sha->mem[index - 7] + sp2;
	}
}

static void		sha_ready(int i, t_sha *sha)
{
	int				index;

	index = -1;
	sha256_shift(i, sha);
	sha->a = sha->hash[0];
	sha->b = sha->hash[1];
	sha->c = sha->hash[2];
	sha->d = sha->hash[3];
	sha->e = sha->hash[4];
	sha->f = sha->hash[5];
	sha->g = sha->hash[6];
	sha->h = sha->hash[7];
	while (++index < 64)
		sha256_loop(index, sha);
	sha->hash[0] += sha->a;
	sha->hash[1] += sha->b;
	sha->hash[2] += sha->c;
	sha->hash[3] += sha->d;
	sha->hash[4] += sha->e;
	sha->hash[5] += sha->f;
	sha->hash[6] += sha->g;
	sha->hash[7] += sha->h;
}

static void		sha_set(char *s, t_sha *sha)
{
	int				i;
	uint64_t		len;

	i = -1;
	len = 0;
	while (++i < 8)
		sha->hash[i] = g_sha256_v[i];
	if (s != NULL)
		sha->set = (ft_strlen(s) + 8) / 64 + 1;
	else
		sha->set = 1;
	sha->msg = (unsigned char *)malloc(64 * sha->set);
	i = -1;
	while (++i < (int)(64 * sha->set))
		sha->msg[i] = 0;
	i = -1;
	while (s && s[++i])
		sha->msg[i] = s[i];
	sha->msg[i == -1 ? 0 : i] = 1 << 7;
	len = i << 3;
	i = -1;
	while (++i < 8)
		sha->msg[64 * sha->set - i - 1] = len >> (i * 8);
}

void			ft_sha256(char *s)
{
	t_sha		sha;
	int			i;

	i = -1;
	ft_bzero(&sha, 11);
	sha_set(s, &sha);
	while (++i < (int)(sha.set))
		sha_ready(i, &sha);
	i = -1;
	while (++i < 8)
		ft_printf("%.8x", sha.hash[i]);
	free(sha.msg);
}