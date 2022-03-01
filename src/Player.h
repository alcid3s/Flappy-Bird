#pragma once
#include "raylib.h"

class Player{
    public:
    Player();
    ~Player();

    void update(int width, int height);
    void draw();
    Vector2 getPosition();

    Texture2D getTexture();
};