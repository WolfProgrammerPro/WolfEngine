#pragma once



#define SIZE_MULTIPLIER 8
#define REAL_WIDTH 160
#define REAL_HEIGHT 128

#define MAP_WIDTH (REAL_WIDTH / SIZE_MULTIPLIER)
#define MAP_HEIGHT (REAL_HEIGHT / SIZE_MULTIPLIER)
#define STARTER_PLAYER_POSITION_X 3
#define STARTER_PLAYER_POSITION_Y 3
#define MINIMAL_JOYSTICK_DEVIATION_TO_MOVE 500
#define JOYSTICK_READ_MINIMAL_COOLDOWN 25
#define LEVEL_COUNT 4
#define MAX_GAME_OBJECTS_PER_LEVEL 10
#define PLAYER_SIZE_X 1
#define PLAYER_SIZE_Y 1

#define MINIMAL_STEP_ON_MAP 0.25f
#define PLAYER_SPEED MINIMAL_STEP_ON_MAP




#define COLOR_BLACK   ST77XX_BLACK
#define COLOR_BLUE    ST77XX_BLUE
#define COLOR_RED     ST77XX_RED
#define COLOR_GREEN   ST77XX_GREEN
#define COLOR_YELLOW  ST77XX_YELLOW
#define COLOR_WHITE   ST77XX_WHITE
#define COLOR_ORANGE  ST77XX_ORANGE
#define COLOR_CYAN    ST7735_CYAN
#define COLOR_BROWN   0x9283

#define BACKGROUND_COLOR COLOR_BLACK

#define TEXTURE_DEFAULT_SIZE SIZE_MULTIPLIER

#define FPS_TEXT_POSITION_X 105
#define FPS_TEXT_POSITION_Y 5
#define FPS_TEXT_SIZE 1
#define FPS_TEXT_COLOR COLOR_WHITE
#define FPS_BACKGROUND_SIZE_X 46
#define FPS_BACKGROUND_SIZE_Y 10
#define FPS_SHOW_DELAY 500

#define PHYSICS_2D_FALL_DELAY 100

enum GameObjectType
{
    NONE,
    WALL,
    PLAYER,
    KEY,
    DOOR,
    FINISH
};


struct Vector2
{
    float x;
    float y;

    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        return x != other.x || y != other.y;
    }
    Vector2 operator*(short scalar) const
    {
        Vector2 result;
        result.x = x * scalar;
        result.y = y * scalar;
        return result;
    }

    Vector2 operator+(const Vector2& other) const
    {
        Vector2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};
