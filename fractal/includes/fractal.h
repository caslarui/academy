/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:30:19 by cion              #+#    #+#             */
/*   Updated: 2018/03/13 18:19:11 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define HEIGHT             1000
# define WIDTH              1000
# define KEY_LEFT           123
# define KEY_DOWN           125
# define KEY_RIGHT          124
# define KEY_UP             126
# define KEY_R 				15
# define KEY_ESCAPE			53

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <../libft/includes/libft.h>

#define sqr(x) ((x)*(x))

typedef struct	s_img
{
	char *name;
	int colors[144];
	char *px;
	double x;
	double y;
	double zoom;
	void *win;
	void *mlx;
	void *img;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	double cRe;
	double cIm;
	double pr;
	double pi;
	int maxIt;
}				t_img;

int 				my_mouse_func(int k, int x, int y, t_img *data);
int					my_key_func(int k, t_img *point);
t_img				*initialize(void);
void 				Julia(t_img *data);
void				mandelbrot(t_img *data);
void    			p_t_img(t_img *data, int color, int x, int y);
void    			img_clear(t_img *data);
void				color1(t_img *data);
void				color2(t_img *data);
void				color3(t_img *data);
void				color4(t_img *data);
void				color5(t_img *data);
void				color6(t_img *data);
void				color_init(t_img *data);
void    			prnt_fractal(t_img *data);
void    			Newton(t_img *data);
void    			Mandel(t_img *data);

#endif

// const unsigned int COLOR_TABLE[] = {
//     0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
//     0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
//     0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
//     0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
//     0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
//     0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
//     0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
//     0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
//     0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
//     0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
//     0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
//     0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
//     0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
//     0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
//     0xffe0, 0x9e66, 0x0000
// };