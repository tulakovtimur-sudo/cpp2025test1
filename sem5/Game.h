#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Background.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <vector>

class Game
{
private:
    sf::RenderWindow window;
    sf::ConvexShape player;
    UI ui;
    Background background;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    int score;
    int lives;
    float playerSpeed;
    float shootCooldown;
    float currentCooldown;
    int maxBullets;
    int maxAsteroids;
    float asteroidSpawnTimer;
    float asteroidSpawnDelay;
    float asteroidBaseSpeed;
    float gameTime;

public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void shoot();
    void spawnAsteroid();
    void checkCollisions();
    void gameOver();
    float getCurrentCooldown();
};