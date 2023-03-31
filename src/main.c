#include "mlx.h"
#include "ant_sim.h"

int	keypress(int k, t_render *r)
{
	if (k == 65307 || k == 53)
		exit(1);
	return (0);
}

int	render_next_frame(t_render *r)
{
	//printf("x = %f\ny = %f\n\n\n\n\n", r->allBalls[0].pos.y, r->allBalls[0].pos.x);
	updateAllBalls(r);
	mlx_put_image_to_window(r->mlx, r->mlx_win, r->img, 0, 0);

	return (1);
}

void spawnBalls(t_render *r)
{
	r->allBalls = malloc(sizeof(t_ball) * (r->ball_num + 1));

	for (int i = 0; i <= r->ball_num; i++)
	{
		r->allBalls[i].acc.x = 0;
		r->allBalls[i].acc.y = 0;

		r->allBalls[i].pos.y = rand() % r->h;
		r->allBalls[i].pos.x = rand() % r->w;

		r->allBalls[i].oldPos.y = r->allBalls[i].pos.y;
		r->allBalls[i].oldPos.x = r->allBalls[i].pos.x;
	}
}

int	main(int argc, const char **argv)
{
	gravity.x = 0.0f;
	gravity.y = 1000.0f;
	t_render	*r;

	r = malloc(sizeof(t_render));

	r->w = 2000;
	r->h = 1200;
	r->mlx = mlx_init();
	r->mlx_win = mlx_new_window(r->mlx, r->w, r->h, "ant_sim");
	r->img = mlx_new_image(r->mlx, r->w, r->h);
	r->addr = mlx_get_data_addr(r->img, &r->bits_per_pixel, &r->line_length, &r->endian);

	r->ball_num = 1000;
	spawnBalls(r);

	mlx_loop_hook(r->mlx, render_next_frame, r);
	mlx_loop(r->mlx);
}
