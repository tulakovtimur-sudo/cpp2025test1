#pragma once
#include <SFML/Graphics.hpp>

// Окно
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Время
const float MAX_DELTA_TIME = 0.033f;
const float GAME_TIME_DIVISOR = 60.f;

// Корабль
const float PLAYER_WIDTH = 36.f;
const float PLAYER_HEIGHT = 40.f;
const float PLAYER_SPEED = 400.f;
const float PLAYER_START_X = 380.f;
const float PLAYER_START_Y = 550.f;
const float BULLET_OFFSET_Y = 25.f;  // Смещение пули от центра корабля

// Форма корабля (точки)
const sf::Vector2f PLAYER_POINTS[] = {
    {0.f, -25.f},   // Нос (верх)
    {18.f, -5.f},   // Правое крыло
    {18.f, 10.f},   // Правая нижняя часть
    {0.f, 15.f},    // Центр низа
    {-18.f, 10.f},  // Левая нижняя часть
    {-18.f, -5.f}   // Левое крыло
};
const int PLAYER_POINT_COUNT = 6;
const sf::Color PLAYER_COLOR = sf::Color(80, 180, 255);
const float PLAYER_OUTLINE_THICKNESS = 2.f;
const sf::Color PLAYER_OUTLINE_COLOR = sf::Color::White;

// Пули
const float BULLET_WIDTH = 4.f;
const float BULLET_HEIGHT = 10.f;
const float BULLET_SPEED = 600.f;
const int MAX_BULLETS = 20;
const float SHOOT_COOLDOWN_MAX = 0.5f;
const float SHOOT_COOLDOWN_MIN = 0.1f;
const sf::Color BULLET_COLOR = sf::Color::Yellow;
const float BULLET_OUTLINE_THICKNESS = 1.f;
const sf::Color BULLET_OUTLINE_COLOR = sf::Color::White;

// Форма астероида
const int ASTEROID_POINT_COUNT = 8;
const sf::Vector2f ASTEROID_POINTS[] = {
    {0.f, -15.f},
    {10.f, -10.f},
    {15.f, 0.f},
    {10.f, 12.f},
    {0.f, 15.f},
    {-12.f, 10.f},
    {-15.f, 0.f},
    {-10.f, -10.f}
};
const sf::Color ASTEROID_COLOR = sf::Color(139, 69, 19);
const float ASTEROID_OUTLINE_THICKNESS = 1.f;
const sf::Color ASTEROID_OUTLINE_COLOR = sf::Color(101, 67, 33);
const float ASTEROID_START_Y = -30.f;
const float ASTEROID_DEFAULT_SPEED = 100.f;

// Астероиды
const int MAX_ASTEROIDS = 30;
const float ASTEROID_BASE_SPEED = 80.f;
const float ASTEROID_MAX_SPEED = 300.f;
const float ASTEROID_SPAWN_DELAY = 1.5f;
const float ASTEROID_SPAWN_DELAY_MIN = 0.5f;
const int ASTEROID_X_MIN = 20;
const int ASTEROID_X_MAX = WINDOW_WIDTH - 20;
const float ASTEROID_SPEED_INCREASE_RATE = 50.f;
const float ASTEROID_SPEED_TIME_DIVISOR = 30.f;
const int ASTEROID_SPEED_RANDOM_MAX = 50;
const float ASTEROID_SPEED_RANDOM_DIVISOR = 10.f;

// Игрок
const int START_LIVES = 3;
const int SCORE_FOR_COOLDOWN = 10;
const float COOLDOWN_REDUCTION = 0.05f;

// Фон
const sf::Color BACKGROUND_COLOR = sf::Color(8, 8, 30);
const int STAR_COUNT = 150;
const int STAR_SIZE_MIN = 1;
const int STAR_SIZE_MAX = 3;
const int STAR_ALPHA_MIN = 50;
const int STAR_ALPHA_MAX = 255;
const float STAR_SPEED = 50.f;
const sf::Color STAR_COLOR = sf::Color(255, 255, 255);

// UI
const float UI_FRAME_WIDTH = 150.f;
const float UI_FRAME_HEIGHT = 50.f;
const float UI_SCORE_X = 10.f;
const float UI_SCORE_Y = 10.f;
const float UI_LIVES_X = 660.f;
const float UI_LIVES_Y = 10.f;
const int UI_FONT_SIZE = 28;
const int UI_TEXT_OFFSET = 10;
const sf::Color UI_SCORE_COLOR = sf::Color(100, 200, 255);
const sf::Color UI_LIVES_COLOR = sf::Color(255, 100, 100);
const sf::Color UI_BG_COLOR = sf::Color(0, 0, 0, 180);
const float UI_OUTLINE_THICKNESS = 2.f;

// Game Over
const int GAME_OVER_FONT_SIZE = 50;
const int FINAL_SCORE_FONT_SIZE = 30;
const int EXIT_FONT_SIZE = 20;
const float GAME_OVER_X = 250.f;
const float GAME_OVER_Y = 250.f;
const float FINAL_SCORE_X = 310.f;
const float FINAL_SCORE_Y = 320.f;
const float EXIT_TEXT_X = 320.f;
const float EXIT_TEXT_Y = 400.f;
const sf::Color GAME_OVER_COLOR = sf::Color::Red;
const sf::Color FINAL_SCORE_COLOR = sf::Color::White;
const sf::Color EXIT_TEXT_COLOR = sf::Color::Yellow;

// Управление
const float MOVE_LEFT = -1.f;
const float MOVE_RIGHT = 1.f;
const float MOVE_STOP = 0.f;