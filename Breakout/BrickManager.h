#pragma once
#include <vector>
#include "Brick.h"
#include <SFML/Graphics.hpp>

/*
#ifdef BRICKMANAGER_DLL_EXPORTS
#define BRICKMANAGER_API __declspec(dllexport)
#else
#define BRICKMANAGER_API __declspec(dllimport)
#endif */

class GameManager;

class  BrickManager {
public:
    BrickManager(sf::RenderWindow* window, GameManager* gameManager);
    void createBricks(int rows, int cols, float brickWidth, float brickHeight, float spacing);
    void render();
    int checkCollision(sf::CircleShape& ball, sf::Vector2f& direction);

    /*
    extern "C" {
        BRICKMANAGER_API BrickManager* CreateBrickManager(sf::RenderWindow* window, GameManger* gameManger);
        BRICKMANGER_API void DestroyBrickManger(BrickManager* brickManager);
    }*/

private:
    std::vector<Brick> _bricks;
    sf::RenderWindow* _window;

    GameManager* _gameManager;
    static constexpr float TOP_PADDING = 100.0f;
};
