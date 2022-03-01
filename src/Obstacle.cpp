#include "Obstacle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Obstacle::Obstacle(int height){
    srand(time(0));
    safeZone = 0;
    while(safeZone < 300){
        safeZone = rand() % (height - 300);
    }

    position = {(float) 1800, (float) 1};
}

Obstacle::Obstacle(int height, int pos){
    srand(time(0));
    safeZone = 0;
    while(safeZone < 250){
        safeZone = rand() % (height - 250);
    }

    position = {2000.0f + pos, 1};
}

Obstacle::~Obstacle(){

}

void Obstacle::update(){
   Vector2 lastPos = position;
   position.x = {(position.x + (position.x - lastPos.x - 4))};
}

void Obstacle::draw(int &height){
    DrawRectangle(position.x, position.y, 80, 2000, BLACK);
    DrawRectangle(position.x, safeZone, 80, 300, WHITE);
}

int Obstacle::getPosX(){
    return position.x;
}

int Obstacle::getSafeZone(){
    return safeZone;
}