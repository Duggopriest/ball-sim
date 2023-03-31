/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_sim.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:19 by jgobbett          #+#    #+#             */
/*   Updated: 2023/03/10 17:48:48 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_SIM_H
# define ANT_SIM_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct s_render	t_render;

typedef struct Vec2
{
	float x;
	float y;
} Vec2;

typedef struct s_ball
{
	Vec2 pos;
	Vec2 oldPos;
	Vec2 acc;
}	t_ball;

Vec2 gravity;

typedef struct Solver
{
	
} Solver;

// holds the everything so I can pass this as a semi global var
typedef struct s_render {
	
	t_ball		*allBalls;
	int			ball_num;

	int			h;
	int			w;
	void		*mlx;
	void		*mlx_win;

	void		*img;
	char		*addr;
	int			endian;
	int			line_length;
	int			bits_per_pixel;
}	t_render;

int			ft_atoi(const char *str);
int			render_next_frame(t_render *render);
void		render_new_frame(t_render *r);

int			pixel_get(t_render *r, int x, int y);
void		pixel_put(t_render *r, int x, int y, int color);

int			dist(int fx, int fy, int sx, int sy);

// ball
void updateAllBalls(t_render *r);
void draw_ball(t_render *r, t_ball *ball,int color);
void accelerate(Vec2 acc, t_ball *ball);
void updateBall(float dt, t_ball *ball);

// math
Vec2 scaleV(Vec2 a, float b);
Vec2 addV(Vec2 a, Vec2 b);
Vec2 subV(Vec2 a, Vec2 b);
float ft_sqrt( float number);
Vec2 DevV(Vec2 a, float b);

#endif
