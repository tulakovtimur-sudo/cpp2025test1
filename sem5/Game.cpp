#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "Constants.h"
#include <random>

Game::Game() :
    window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Cosmic Shooter"),
    score(0),
    lives(START_LIVES),
    playerSpeed(PLAYER_SPEED),
    shootCooldown(SHOOT_COOLDOWN_MAX),
    currentCooldown(0.f),
    maxBullets(MAX_BULLETS),
    maxAsteroids(MAX_ASTEROIDS),
    asteroidSpawnTimer(0.f),
    asteroidSpawnDelay(ASTEROID_SPAWN_DELAY),
    asteroidBaseSpeed(ASTEROID_BASE_SPEED),
    gameTime(0.f)
{
    window.setFramerateLimit(60);
    player = createPlayer();

    bullets.resize(maxBullets);
    asteroids.resize(maxAsteroids);
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen() && lives > 0)
    {
        float deltaTime = clock.restart().asSeconds();
        if (deltaTime > MAX_DELTA_TIME) deltaTime = MAX_DELTA_TIME;

        gameTime += deltaTime;

        processEvents();
        update(deltaTime);
        render();
    }

    if (lives <= 0)
    {
        gameOver();
    }
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

float Game::getCurrentCooldown()
{
    float reduction = (score / SCORE_FOR_COOLDOWN) * COOLDOWN_REDUCTION;
    float newCooldown = SHOOT_COOLDOWN_MAX - reduction;

    if (newCooldown < SHOOT_COOLDOWN_MIN) newCooldown = SHOOT_COOLDOWN_MIN;
    if (newCooldown > SHOOT_COOLDOWN_MAX) newCooldown = SHOOT_COOLDOWN_MAX;

    return newCooldown;
}

void Game::update(float deltaTime)
{
    if (currentCooldown > 0)
    {
        currentCooldown -= deltaTime;
    }

    if (isShooting() && currentCooldown <= 0)
    {
        shoot();
        currentCooldown = getCurrentCooldown();
    }

    float currentSpawnDelay = asteroidSpawnDelay - (gameTime / GAME_TIME_DIVISOR);
    if (currentSpawnDelay < ASTEROID_SPAWN_DELAY_MIN) currentSpawnDelay = ASTEROID_SPAWN_DELAY_MIN;

    asteroidSpawnTimer += deltaTime;
    if (asteroidSpawnTimer >= currentSpawnDelay)
    {
        asteroidSpawnTimer = 0.f;
        spawnAsteroid();
    }

    float move = getPlayerMovement();
    sf::Vector2f pos = player.getPosition();
    pos.x += move * playerSpeed * deltaTime;

    if (pos.x < 0) pos.x = 0;
    if (pos.x > WINDOW_WIDTH - PLAYER_WIDTH) pos.x = WINDOW_WIDTH - PLAYER_WIDTH;
    player.setPosition(pos);

    for (auto& bullet : bullets)
    {
        bullet.update(deltaTime);
    }

    for (auto& asteroid : asteroids)
    {
        asteroid.update(deltaTime);
    }

    checkCollisions();
    background.update(deltaTime);
    ui.updateScore(score);
    ui.updateLives(lives);
}

void Game::shoot()
{
    sf::Vector2f playerPos = player.getPosition();

    for (auto& bullet : bullets)
    {
        if (!bullet.isActive())
        {
            bullet.shoot(playerPos.x, playerPos.y);
            break;
        }
    }
}

void Game::spawnAsteroid()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDist(ASTEROID_X_MIN, ASTEROID_X_MAX);
    std::uniform_int_distribution<> speedDist(0, 50);

    float x = static_cast<float>(xDist(gen));
    float y = ASTEROID_START_Y;
    float speed = asteroidBaseSpeed + (gameTime / ASTEROID_SPEED_TIME_DIVISOR) * ASTEROID_SPEED_INCREASE_RATE + speedDist(gen) / 10.f;
    if (speed > ASTEROID_MAX_SPEED) speed = ASTEROID_MAX_SPEED;

    for (auto& asteroid : asteroids)
    {
        if (!asteroid.isActive())
        {
            asteroid.spawn(x, y, speed);
            break;
        }
    }
}

void Game::checkCollisions()
{
    for (auto& bullet : bullets)
    {
        if (!bullet.isActive()) continue;

        for (auto& asteroid : asteroids)
        {
            if (!asteroid.isActive()) continue;

            if (bullet.getBounds().findIntersection(asteroid.getBounds()))
            {
                bullet.deactivate();
                asteroid.deactivate();
                score++;
                break;
            }
        }
    }

    sf::FloatRect playerBounds = player.getGlobalBounds();

    for (auto& asteroid : asteroids)
    {
        if (!asteroid.isActive()) continue;

        if (playerBounds.findIntersection(asteroid.getBounds()))
        {
            asteroid.deactivate();
            lives--;

            if (lives <= 0)
            {
                return;
            }
            break;
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);

    background.draw(window);

    for (auto& bullet : bullets)
    {
        bullet.draw(window);
    }

    for (auto& asteroid : asteroids)
    {
        asteroid.draw(window);
    }

    drawPlayer(window, player);
    ui.draw(window);

    window.display();
}

void Game::gameOver()
{
    window.clear(sf::Color::Black);
    ui.showGameOver(window, score);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
    }
}