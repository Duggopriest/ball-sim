#include "ant_sim.h"

void	pixel_put(t_render *r, int x, int y, int color)
{
	char	*dst;

	dst = r->addr + (y * r->line_length + x * (r->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	pixel_get(t_render *r, int x, int y)
{
	char	*dst;

	dst = r->addr + (y * r->line_length + x * (r->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void draw_balls(t_render *r)
{
	
}