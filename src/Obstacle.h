#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

class Obstacle {
    private:
    Vector2 position;
    int safeZone;

    public:
    Obstacle(int height);
    Obstacle(int height, int position);
    ~Obstacle();

    void update();
    void draw(int &height);

    int getPosX();
    int getSafeZone();
};

#endif