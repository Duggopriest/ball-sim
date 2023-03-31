#include "ant_sim.h"


Vec2 subV(Vec2 a, Vec2 b)
{
	Vec2 new;
	new.x = a.x - b.x;
	new.y = a.y - b.y;
	return new;
}

Vec2 addV(Vec2 a, Vec2 b)
{
	Vec2 new;
	new.x = a.x + b.x;
	new.y = a.y + b.y;
	return new;
}

Vec2 scaleV(Vec2 a, float b)
{
	Vec2 new;
	new.x = a.x * b;
	new.y = a.y * b;
	return new;
}

Vec2 DevV(Vec2 a, float b)
{
	Vec2 new;
	new.x = a.x / b;
	new.y = a.y / b;
	return new;
}

void updateBall(float dt, t_ball *ball)
{
	Vec2 vel = subV(ball->pos, ball->oldPos);

	ball->oldPos = ball->pos;

	ball->pos = addV( addV( ball->pos , vel), scaleV( scaleV(ball->acc, dt), dt));
}

void accelerate(Vec2 acc, t_ball *ball)
{
	ball->acc = addV(ball->acc, acc);
}

void draw_ball(t_render *r, t_ball *ball, int color)
{
	if (ball->pos.x > r->w || ball->pos.x < 0 || ball->pos.y > r->h || ball->pos.y < 0)
		return;
	int offsetX, offsetY;
	for(int i=0;i<50;++i)
	{
		offsetX = sin(2*3.14159*i/50.0) * 10;
		offsetY = cos(2*3.14159*i/50.0) * 10;
		pixel_put(r, offsetX + ball->pos.x - 1, offsetY + ball->pos.y, color);
		pixel_put(r, offsetX + ball->pos.x + 1, offsetY + ball->pos.y, color);
	}
}