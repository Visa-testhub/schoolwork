/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:28:11 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/29 16:22:24 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> /* DELET THIS */

typedef struct		tetrimino{
	unsigned char	type;
	unsigned long	block;
}					tblock;

typedef struct		grid{
	unsigned short	lines[16];
}					t_map;
/*
typedef struct		gridsize{
	unsigned long	masks[16];
}
*/
enum	btype
{
	UP_L = 0x80008000C0000000,
	LEFT_L = 0x2000E00000000000,
	DOWN_L = 0xC000400040000000,
	RIGHT_L = 0xE000800000000000,
	UP_J = 0x40004000C0000000,
	LEFT_J = 0xE000200000000000,
	DOWN_J = 0xC000800080000000,
	RIGHT_J = 0x8000E00000000000,
	UP_T = 0xE000400000000000,
	LEFT_T = 0x8000C00080000000,
	DOWN_T = 0x4000E00000000000,
	RIGHT_T = 0x4000C00040000000,
	HORIZONTAL_S = 0x6000C00000000000,
	VERTICAL_S = 0x8000C00040000000,
	HORIZONTAL_Z = 0xC000600000000000,
	VERTICAL_Z = 0x4000C00080000000,
	HORIZONTAL_LINE = 0xF000000000000000,
	VERTICAL_LINE = 0x8000800080008000,
	SQUARE = 0xC000C00000000000
};

enum	masks
{
	mask2 = 0x3FFF3FFFFFFFFFFF,
	mask3 = 0x1FFF1FFF1FFFFFFF,
	mask4 = 0xFFF0FFF0FFF0FFF,
	mask5 = 0x7FF07FF07FF07FF,
	mask6 = 0x3FF03FF03FF03FF,
	mask7 = 0x1FF01FF01FF01FF,
	mask8 = 0xFF00FF00FF00FF,
	mask9 = 0x7F007F007F007F,
	mask10 = 0x3F003F003F003F,
	mask11 = 0x1F001F001F001F,
};

int 				main(int argc, char **argv);
void				validate(tblock *blocks, int fd);
void				assemble(tblock *blocks);
void				usage_and_exit(int errortype);

#endif
