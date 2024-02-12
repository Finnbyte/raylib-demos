#ifndef __BOUNCING_BALL_H__
#define __BOUNCING_BALL_H__

typedef struct {
    int radius;
    int y;
    int velocity;
} Ball;

void UpdateBall(Ball *ball);
void DrawBall(Ball *ball);


#endif // !__BOUNCING_BALL_H__
