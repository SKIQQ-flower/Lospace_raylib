#include "player.hpp"
#include "raymath.h"

void Player::Update()
{
    float dt = GetFrameTime();
    input_vector = Vector2{0, 0};

    const float deadZone = 0.1f;
    float gamepad_x = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
    float gamepad_y = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);

    if (fabs(gamepad_x) > deadZone || fabs(gamepad_y) > deadZone)
    {
        input_vector.x = gamepad_x;
        input_vector.y = gamepad_y;

        if (gamepad_x < -deadZone)
            direction = Direction::LEFT;
        if (gamepad_x > deadZone)
            direction = Direction::RIGHT;
        if (gamepad_y < -deadZone)
            direction = Direction::UP;
        if (gamepad_y > deadZone)
            direction = Direction::DOWN;
    }
    else
    {
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
            input_vector.x = -1.0f;
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
            input_vector.x = 1.0f;
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP))
            input_vector.y = -1.0f;
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
            input_vector.y = 1.0f;
    }

    bool left = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    bool right = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
    bool up = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
    bool down = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

    if (left && !right)
        input_vector.x = -1.0f;
    if (right && !left)
        input_vector.x = 1.0f;
    if (up && !down)
        input_vector.y = -1.0f;
    if (down && !up)
        input_vector.y = 1.0f;

    if (Vector2Length(input_vector) > 0.0f)
    {
        input_vector = Vector2Normalize(input_vector);
    }

    velocity = Vector2Scale(input_vector, speed_ * dt);
    position = Vector2Add(position, velocity);
    DrawRectangle(position.x, position.y, 40, 40, RED);
}
