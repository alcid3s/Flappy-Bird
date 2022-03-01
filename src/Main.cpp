#include "raylib.h"
#include "Player.h"
#include "Obstacle.h"
#include <vector>
#include <iostream>

void draw(std::vector<Obstacle> &list, Player &player, int height);
void update(std::vector<Obstacle> &list, Player &player, int width, int height);
void hitsPole(std::vector <Obstacle> &list, Player &player, bool &flag);

std::vector<Obstacle> spawnNewObject(std::vector<Obstacle> &list, int height);

int main() {

    // Initializtion
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int distance = 2.0f;

    SetTraceLogLevel(LOG_NONE);
    InitWindow(screenWidth, screenHeight, "Game");

    float deltaTime = 0;
    Player player;
    SetTargetFPS(60);

    std::vector<Obstacle> obstacleList;

    bool flag = true;
    while(!WindowShouldClose() && flag){
        // Create new object every 200 frames.
        deltaTime += distance * GetFrameTime();

        if(deltaTime >= 6){
           obstacleList = spawnNewObject(obstacleList, screenHeight);
           obstacleList.shrink_to_fit();
           deltaTime = 0;
        }

        // Updatable.
        update(obstacleList, player, screenWidth, screenHeight);
        
        // Drawing
        draw(obstacleList, player   , screenHeight);

        hitsPole(obstacleList, player, flag);
    }

    CloseWindow();
    return 0;
}

std::vector<Obstacle> spawnNewObject(std::vector<Obstacle> &list, int height){
    Obstacle obstacle(height);
    list.insert(list.begin(), obstacle);
    if(list.size() > 5){
        list.pop_back();
    }
    list.shrink_to_fit();
    return list;
}

void update(std::vector<Obstacle> &list, Player &player, int width, int height){
    for (size_t i = 0; i < list.size(); i++)
    {
        list.at(i).update();
    }

    player.update(width, height);
}

void draw(std::vector<Obstacle> &list, Player &player, int height){
        BeginDrawing();
        ClearBackground(GRAY);
        
        player.draw();

            for (size_t i = 0; i < list.size(); i++)
    {
        list.at(i).draw(height);
    }
        EndDrawing();
}

void hitsPole(std::vector <Obstacle> &list, Player &player, bool &flag){
    for (size_t i = 0; i < list.size(); i++)
    {
        if(player.getPosition().x == list.at(i).getPosX()){
            if(player.getPosition().y > list.at(i).getSafeZone() && player.getPosition().y < list.at(i).getSafeZone() + 300){
            }else{
                flag = false;
            }
        }
    }
} 