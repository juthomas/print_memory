/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:05:08 by exam              #+#    #+#             */
/*   Updated: 2016/05/01 16:52:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	put_exa(int nb, int len)
{
	if (len > 0)
		put_exa(nb / 16, len - 1);
	if (nb % 16 >= 0 && nb % 16 <= 9)
		ft_putchar(nb % 16 + 48);
	else
		ft_putchar(nb % 16 + 'a' - 10);
}

void	print_memory(const void *addr, size_t size)
{
    unsigned int i;

	unsigned int		tmp;
	void				*addr_tmp;
	unsigned char		*visi;
	short int			first;
	unsigned int		re;

	//size = size / sizeof(int);
	addr_tmp = (void*)addr;
	visi = addr_tmp;
	i = 0;
	tmp = 0;
	first = 1;
	while (i < size)
	{
		put_exa(visi[i], 1);
		if (i % 2 == 1 && i != 0)
			ft_putstr(" ");
		if ((i + 1) % 16 == 0 && i != 0)
		{
			first = 0;
			while ((tmp ) % 16 != 0 || first == 0)
			{
				if (visi[tmp] >= 32 && visi[tmp] <= 126)
					ft_putchar(visi[tmp]);
				else
					ft_putchar('.');
				//ft_putstr("...");
				first = 1;
				tmp++;
			}
			ft_putchar('\n');
			tmp = i + 1;
		}
		i++;
	}
		if ((i) % 16 != 0 && i != 0)
		{
//			put_exa(i%12, 1);
			re = (16 - (i % 16)) * 2;
			re = re + ((16 - (i % 16) + 1) / 2);
			while (re > 0)
			{
				ft_putchar(' ');
				re--;
			}
			first = 0;
			while (tmp < size)
			{
				if (visi[tmp] >= 32 && visi[tmp] <= 126)
					ft_putchar(visi[tmp]);
				else
					ft_putchar('.');
//				ft_putstr("...");
				first = 1;
				tmp++;
			}
			ft_putchar('\n');
			tmp = i;
		}
}


int		main(void)
{
	int i;
	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
//	print_bytes(tab, sizeof(tab));
//	ft_putstr("\n\n");
	i = 0;
	char *retab;
	retab = (char*)malloc(sizeof(char) * 256);
	while (i < 256)
	{
		retab[i] = i;
		i++;
	}
//	char tabl[11] = {'e', 'g', 'p', 'q', 'e', 'f'};
	print_memory(retab, 277);
	
	//	print_bytes(tabl, sizeof(tabl));
	return (0);
}
