#include "raylib.h"
#include "Player.h"
#include <iostream>

Texture2D texture;
Vector2 pos;
bool firstTimeUpdate;
bool firstTimeDraw;

Player::Player(){
    firstTimeUpdate = true;
    firstTimeDraw = true;
}

Player::~Player(){

}

void Player::update(int width, int height){
    if(firstTimeUpdate){
        pos = { (float) width / 8, (float) height / 2};
        firstTimeUpdate = false;
    }

    Vector2 lastPos = pos;

    if(IsKeyDown(KEY_SPACE)){
        pos.y -= 10.0f;
    }

    if(pos.y >= 1300){
        pos.y = 500;
    }

    pos = {pos.x + (pos.x - lastPos.x), pos.y + (pos.y - lastPos.y + 4)};
}   

void Player::draw(){
    if(firstTimeDraw){
        Image image = LoadImage("../res/Player.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        image = LoadImageFromTexture(texture);
        UnloadTexture(texture);

        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        firstTimeDraw = false;
    }

    DrawTexture(texture, pos.x, pos.y, MAROON);
}

Texture2D getTexture(){
    return texture;
}

Vector2 Player::getPosition(){
    return pos;
}