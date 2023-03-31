#include "ant_sim.h"
// void updateSolver(float dt)
// {

// }

void updatePos(float dt, t_render *r)
{
	for (int i = 0; i <= r->ball_num; i++)
		updateBall(dt, &r->allBalls[i]);
}

void applyGrav(t_render *r)
{
	for (int i = 0; i <= r->ball_num; i++)
		accelerate(gravity, &r->allBalls[i]);
}

void resetAcc(t_ball *ball)
{
	ball->acc.x = 0;
	ball->acc.y = 0;
}

void applyConstraint(t_render *r)
{
	for (int i = 0; i <= r->ball_num; i++)
	{
		t_ball *ball = &r->allBalls[i];

		// if (ball->pos.x > r->w)
		// {
		// 	ball->pos.x = 500;
		// 	resetAcc(ball);
		// 	continue;
		// }
		// if (ball->pos.x < 0)
		// {
		// 	ball->pos.x = 500;
		// 	resetAcc(ball);
		// 	continue;
		// }
		// if (ball->pos.y > r->h)
		// {
		// 	ball->pos.y = 500;
		// 	resetAcc(ball);
		// 	continue;
		// }
		// if (ball->pos.y < 0)
		// {
		// 	ball->pos.y = 500;
		// 	resetAcc(ball);
		// 	continue;
		// }

		
		if (ball->pos.x > r->w - 10)
		{
			ball->pos.x = r->w - 10;
			continue;
		}
		else if (ball->pos.x < 10)
		{
			ball->pos.x = 10;
			continue;
		}
		else if (ball->pos.y > r->h - 10)
		{
			ball->pos.y = r->h - 10;
			continue;
		}
		else if (ball->pos.y < 10)
		{
			ball->pos.y = 10;
			continue;
		}
	}
}

void constrain(t_render *r, t_ball *ball)
{
	if (ball->pos.x > r->w - 10)
	{
		ball->pos.x = r->w - 10;
	}
	if (ball->pos.x < 10)
	{
		ball->pos.x = 10;
	}
	if (ball->pos.y > r->h - 10)
	{
		ball->pos.y = r->h - 10;
	}
	if (ball->pos.y < 10)
	{
		ball->pos.y = 10;
	}
}


double	length_squared(Vec2 v3)
{
	return (v3.x * v3.x + v3.y * v3.y);
}

float	length(Vec2 v3)
{
	return sqrt(v3.x * v3.x + v3.y * v3.y);
	//return (ft_sqrt(length_squared(v3)));
}

Vec2 addVI(Vec2 a, float b)
{
	Vec2 new;
	new.x = a.x + b;
	new.y = a.y + b;
	return new;
}

void solveCollisions(t_render *r)
{
	for (int i = 0; i <= r->ball_num; i++)
	{
		t_ball *ballA, *ballB;
		
		ballA = &r->allBalls[i];
		for (int j = 0; j <= r->ball_num; j++)
		{
			if (j == i)
				continue;
			ballB = &r->allBalls[j];

			Vec2 coll_axis = subV(ballA->pos, ballB->pos);
			float dist = length(coll_axis);
			if (dist < 20.0f)
			{
				
				Vec2 n = DevV(coll_axis, dist);
				float delta = 20.0f - dist;

				Vec2 deltaV = scaleV(n, 0.5f * delta);
				ballA->pos = addV(ballA->pos, scaleV(n, 0.5f * delta));
				constrain(r, ballA);
				ballB->pos = subV(ballB->pos, scaleV(n, 0.5f * delta));
				constrain(r, ballB);
			}
		}
	}
}


void updateAllBalls(t_render *r)
{
	t_ball *ball = &r->allBalls[0];
	float dt = 0.001f;

	for (int i = 0; i <= r->ball_num; i++)
		draw_ball(r, &r->allBalls[i], 0);

	applyGrav(r);
	applyConstraint(r);
	solveCollisions(r);
	updatePos(dt, r);

	for (int i = 0; i <= r->ball_num; i++)
		draw_ball(r, &r->allBalls[i], 0xFFFFFFFF);
}